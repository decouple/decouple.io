<?hh // strict
namespace Admin;
use Decouple\Ui\Ui;
use Decouple\Common\Contract\DB\Driver;
use Decouple\Common\Contract\DB\Schema;
use Decouple\HTTP\Request\Uri;
use Decouple\HTTP\Request\Request;
use Decouple\DBAL\Query\Raw;
use Debug\DebugRegistry;

class ArticlesController {
  public function getIndex(
    Driver $driver,
    Schema $schema,
    DebugRegistry $debug
  ): :xhp {
    $articles = $schema->table('articles')->select()->fetchAll();
    return <cms:layout>
      <h1 class="m-b-1">Manage Articles</h1>
      <articles:list articles={$articles} />
    </cms:layout>;
  }

  public function getEdit(
    Schema $schema,
    Uri $uri,
    Request $request
  ): :xhp {
    $article_id = (int)$request->routeParams->at(0);
    $article = $schema->table('articles')->select()->where('id', '=', $article_id)->first();
    if($article) {
      return
        <cms:layout>
          <h1>Editing "{$article['title']}"</h1>
          <form action="/admin/cms/articles/edit/21" method="post">
            <div class="grid">
              <div class="column-6">
                <div class="form--group">
                  <label for="title">Title</label>
                  <input type="text" name="title" value={$article['title']} />
                </div>
              </div>
              <div class="column-6">
                <div class="form--group">
                  <label for="image">Image URL</label>
                  <input type="text" name="image" value={$article['image']} />
                </div>
              </div>
              <div class="column-12">
                <div class="form--group column-12">
                  <div class="form--wysiwyg" contenteditable="true">{$article['content']}</div>
                </div>
              </div>
              <div class="column-3 column-offset-9">
                <button type="submit" class="button button__green button__block">Save</button>
              </div>
            </div>
          </form>
        </cms:layout>;
    } else {
      throw new \Exception("Invalid article requested");
    }
  }

  public function postEdit(
    Schema $schema,
    Uri $uri,
    Request $request
  ): :xhp {

  }
}
