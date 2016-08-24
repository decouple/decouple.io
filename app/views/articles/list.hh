<?hh // strict
class :articles:list extends :x:element {
  attribute Vector<Map<string, mixed>> articles @required;
  public function render(): XHPRoot {
    $articles = $this->getAttribute('articles');
    foreach ($articles as $article) {
      $this->appendChild(<articles:list-item article={$article} />);
    }
    return
      <div class="news--articles-list">
        {$this->getChildren()}
      </div>;
  }
}
