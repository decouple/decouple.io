<?hh // strict
namespace API;
use Decouple\Common\Contract\DB\Driver;
use Decouple\Common\Contract\DB\Schema;
use Decouple\DBAL\Query\Raw;
use Debug\DebugRegistry;
class TestController {
  public function index(
    Driver $driver,
    Schema $schema,
    DebugRegistry $debug
  ): string {
    $schema = $driver->schema('decouple');
    $articles_table = $schema->table('articles');
    $articles = $articles_table->select(
      Vector {'id', 'title', 'content', 'author_id', 'created_at', 'image'},
    )->where('deleted_at', '=', null)->fetchAll();

    return json_encode($articles->toArray());
  }
}
