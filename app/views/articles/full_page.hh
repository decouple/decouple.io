<?hh // decl
class :articles:full_page extends :decouple:ui:base {
  attribute
    KeyedTraversable<string,mixed> article @required;

  protected function compose(): XHPRoot {
    $article = $this->getAttribute('article');
    return
      <div class="news--article__full-page">
        <div class="news--article-inner">
          <h4 class="news--article-title">{$article['title']}</h4>
          <div class="news--article-image">
            <img src={$article['image']} alt={$article['title']} />
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
