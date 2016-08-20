<?hh // strict
namespace Test\DBAL;
use Decouple\Console\CLI\CLI;
use Decouple\Test\TestCase;
use Decouple\DBAL\DPDO\DPDOMySQLDriver;
use Decouple\Registry\Paths;
class DriverTest extends TestCase {
  public function __construct() {}
  public function execute(Paths $paths): void {
    $db_config = hack_require($paths->get('config') . '/database.hh');
    $test_db = $db_config->get('test');
    $driver = new DPDOMySQLDriver();
    $connected = $driver->connect(
      $test_db->get('params'),
      $test_db->get('user'),
      $test_db->get('password'),
    );
    $this->assertEquals($connected, true);
    $schema = $driver->schema('decouple_test');
    if(!$schema->exists()) {
      $schema->create();
    }
    $this->assertEquals($schema->exists(), true);
  }
}
