<?hh // decl
class :news:articleFullPage extends :x:element {
  use XHPAsync;
  attribute
    KeyedTraversable<string,mixed> article @required;

  public async function asyncRender(): Awaitable<XHPRoot> {
    $article = $this->getAttribute('article');
    return
      <div class="news--article__full-page" directive-link="foo" directive-to="/">
        <div class="news--article-inner">
          <h4 class="news--article-title">{$article['title']}</h4>
          <div class="news--article-image">
            <img src={$article['image']}/>
          </div>
          <div class="news--article-content">
            <p class="news--article-description">{$article['content']}</p>
            <div class="news--article-date">{$article['created_at']}</div>
          </div>
        </div>
      </div>
    ;
  }
}
