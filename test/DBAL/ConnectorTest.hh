<?hh // strict
namespace Test\DBAL;
use Decouple\Console\CLI\CLI;
use Decouple\Test\TestCase;
use Decouple\DBAL\DPDO\DPDOConnector;
use Decouple\Registry\Paths;
class ConnectorTest extends TestCase {
  public function execute(Paths $paths): void {
    $db_config = hack_require($paths->get('config') . '/database.hh');
    $test_db = $db_config->get('test');
    $connector = new DPDOConnector();
    $connected = $connector->connect(
      $test_db->get('params'),
      $test_db->get('user'),
      $test_db->get('password'),
    );
    $this->assertEquals($connected, true);
  }
}
