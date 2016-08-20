<?hh // partial
namespace Test\DBAL;
use Decouple\Test\TestCase;
use Decouple\DBAL\DPDO\DPDOMySQLDriver;
use Decouple\Common\Contract\DB\Schema;
use Decouple\Registry\Paths;
class SchemaTest extends TestCase {
  public function execute(Paths $paths): void {
    $db_config = hack_require($paths->get('config') . '/database.hh');
    $test_db = $db_config->get('test');
    $driver = new DPDOMySQLDriver();
    $connected = $driver->connect(
      $test_db->get('params'),
      $test_db->get('user'),
      $test_db->get('password'),
    );
    $schema = $driver->schema('decouple_test');
    $failed = false;
    if(!$schema instanceof Schema) {
      $failed = true;
    }
    $this->assertEquals($failed, false);
  }
}
