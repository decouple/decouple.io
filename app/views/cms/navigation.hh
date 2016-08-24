<?hh // strict
use XHPRoot;
class :cms:navigation extends :decouple:ui:base {
  protected function compose() : XHPRoot {
    return <div class="grid">
      <div class="column-12 m-r-2">
        <nav class="nav__sidebar">
          <h2>Navigation</h2>
          <a href="/admin/cms/taxonomy" class="nav--item nav--item__block">
            Taxonomy
          </a>
          <a href="/admin/cms/articles" class="nav--item nav--item__block">
            Articles
          </a>
          <a href="/admin/cms/media" class="nav--item nav--item__block">
            Media
          </a>
        </nav>
      </div>
    </div>;
  }
}
