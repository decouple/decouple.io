<?hh // strict
class :news:articles extends :x:element {
  use XHPAsync;
  attribute Vector<Map<string, mixed>> articles @required;
  public async function asyncRender(): Awaitable<XHPRoot> {
    $articles = $this->getAttribute('articles');
    foreach ($articles as $article) {
      $this->appendChild(<news:articleListItem article={$article} />);
    }
    return
      <div class="news--articles">
        {$this->getChildren()}
      </div>;
  }
}
