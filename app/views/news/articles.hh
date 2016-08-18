<?hh // strict
class :news:articles extends :x:element {
  attribute Vector<Map<string, mixed>> articles @required;
  public function render(): XHPRoot {
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
