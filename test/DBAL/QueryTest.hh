<?hh // strict
namespace Test\DBAL;
use Decouple\Test\TestCase;
use Decouple\Common\Contract\DB\Query;
use Decouple\DBAL\DPDO\DPDOMySQLDriver;
use Decouple\Registry\Paths;
class QueryTest extends TestCase {
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
    $table = $schema->table('articles');
    $query = $table->select();
    $failed = false;
    if(!$query instanceof Query) {
      $failed = true;
    }
    $this->assertEquals($failed, false);
  }
}
