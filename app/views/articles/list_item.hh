<?hh // decl
class :articles:list_item extends :x:element {
  attribute
    KeyedTraversable<string,mixed> article @required;

  protected function render(): XHPRoot {
    $article = $this->getAttribute('article');
    return
      <div class="news--article">
        <div class="news--article-inner">
          <div class="news--article-image">
            <img src={$article['image']}/>
          </div>
          <h4 class="news--article-title">{$article['title']}</h4>
          <div class="news--article-date">
            <a href={"/admin/cms/articles/edit/" . $article['id']} class="button m-r-2">Edit</a>
            {$article['created_at']}
          </div>
        </div>
      </div>
    ;
  }
}
