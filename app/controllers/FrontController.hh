<?hh // strict
use Decouple\Ui\Ui;
use Decouple\Common\Contract\DB\Driver;
use Decouple\Common\Contract\DB\Schema;
use Decouple\DBAL\Query\Raw;
use Debug\DebugRegistry;
class FrontController {
  public function index(
    Driver $driver,
    Schema $schema,
    DebugRegistry $debug
  ): :xhp {
    $articles = $schema->table('articles')->select()->fetchAll();
    return
      <layouts:front>
        <articles:grid articles={$articles} />
      </layouts:front>
    ;
  }

  public function test(): string {
    return "Test";
  }
}
