<?hh // partial
require_once "functions.hh";

$base_dir = realpath(dirname(dirname(dirname(__FILE__))));
$paths = hack_require($base_dir.'/app/config/paths.hh');
hack_require($base_dir . '/vendor/autoload.php');

use Decouple\Log\Log;
use Decouple\Registry\Registry;
use Decouple\Decoupler\Decoupler;
use Decouple\DBAL\DPDO\DPDOMySQLDriver;
use Debug\DebugRegistry;

// Decoupler configuration
$driver = new DPDOMySQLDriver();
$driver->connect(
  Map {'type' => 'mysql', 'host' => 'localhost'},
  'decouple',
  'secret',
);
$driver->connector()->connection()
  ->setAttribute(PDO::ATTR_DEFAULT_FETCH_MODE, PDO::FETCH_ASSOC);
$schema = $driver->schema('decouple');
$decoupler = new Decoupler(
  Map {
    "Decouple\Registry\Paths" => $paths,
    "Debug\DebugRegistry" => new DebugRegistry(Map {"start_time" => getrusage()}),
    "Decouple\Common\Contract\DB\Driver" => $driver,
    "Decouple\Common\Contract\DB\Schema" => $schema,
  },
);
