<?hh // strict
use Decouple\Ui\Ui;
use Decouple\Common\Contract\DB\Driver;
use Decouple\Common\Contract\DB\Schema;
use Decouple\HTTP\Request\Uri;
use Decouple\DBAL\Query\Raw;
use Debug\DebugRegistry;
class NewsController {
  public function getIndex(
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

  public function getArticle(
    Schema $schema,
    Uri $uri
  ): :xhp {
    $article_id = (int)$uri->parts()->at(2);
    $article = $schema->table('articles')->select()->where('id', '=', $article_id)->first();
    if($article) {
      return
        <layouts:front>
            <articles:full-page article={$article} />
        </layouts:front>;
    } else {
      throw new Exception("Invalid article requested");
    }
  }
}
