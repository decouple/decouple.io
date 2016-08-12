<?hh // strict
use Decouple\Ui\Ui;
use Decouple\Common\Contract\DB\Driver;
use Decouple\Common\Contract\DB\Schema;
use Decouple\HTTP\Request\Uri;
use Decouple\DBAL\Query\Raw;
use Debug\DebugRegistry;
class NewsController {
  public function index(
    Driver $driver,
    Schema $schema,
    DebugRegistry $debug
  ): :xhp {
    $articles = $schema->table('articles')->select()->fetchAll();
    return
      <layouts:front schema={$schema} title="Decouple">
        <news:articles articles={$articles} />
      </layouts:front>
    ;
  }

  public function article(
    Schema $schema,
    Uri $uri
  ): :xhp {
    $article_id = (int)$uri->parts()->at(2);
    $article = $schema->table('articles')->select()->where('id', '=', $article_id)->first();
    if($article) {
      return
        <layouts:front schema={$schema} title="Decouple">
            <news:articleFullPage article={$article} />
        </layouts:front>;
    } else {
      throw new Exception("Invalid article requested");
    }
  }
}
