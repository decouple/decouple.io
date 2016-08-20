<?hh // partial
require_once "functions.hh";

$base_dir = realpath(dirname(dirname(dirname(__FILE__))));
$paths = hack_require($base_dir.'/app/config/paths.hh');
$db_config = hack_require($paths->get('config') . '/database.hh');

hack_require($base_dir . '/vendor/autoload.php');

use Decouple\Log\Log;
use Decouple\Registry\Registry;
use Decouple\DBAL\DPDO\DPDOMySQLDriver;
use Debug\DebugRegistry;

use Decouple\Singleton\Decoupler;

// Decoupler configuration
$driver = new DPDOMySQLDriver();
$log = new Log($paths->get('logs')."/http.log");

// Connect to the default database
$default_db = $db_config->get('default');
try {
  $driver->connect(
    $default_db->get('params'),
    $default_db->get('user'),
    $default_db->get('password'),
  );
  $driver->connector()->connection()
  ->setAttribute(PDO::ATTR_DEFAULT_FETCH_MODE, PDO::FETCH_ASSOC);
} catch(Exception $e) {
  $log->write("Unable to connect to database: " . $e->getMessage() . " (on line " . $e->getLine() . " of " . $e->getFile() . ")");
}

// Register the default schema with the Decoupler
try {
  $schema = $driver->schema($default_db->get('schema'));
} catch(Exception $e) {
  $log->write("Unable to select schema: " . $e->getMessage() . " (on line " . $e->getLine() . " of " . $e->getFile() . ")");
}

Decoupler::setAll(Map {
  "Decouple\Registry\Paths" => $paths,
  "Debug\DebugRegistry" => new DebugRegistry(Map {"start_time" => getrusage()}),
  "Decouple\Common\Contract\DB\Driver" => $driver,
  "Decouple\Common\Contract\DB\Schema" => $schema,
  "Decouple\Log\Log" => $log,
}, false);
