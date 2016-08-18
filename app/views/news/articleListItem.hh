<?hh // decl
class :news:articleListItem extends :x:element {
  attribute
    KeyedTraversable<string,mixed> article @required;

  protected function render(): XHPRoot {
    $article = $this->getAttribute('article');
    return
      <a class="news--article" href={"/news/article/" . $article['id']}>
        <div class="news--article-inner">
          <h4 class="news--article-title">{$article['title']}</h4>
          <div class="news--article-image">
            <img src={$article['image']}/>
          </div>
          <div class="news--article-date">{$article['created_at']}</div>
        </div>
      </a>
    ;
  }
}
