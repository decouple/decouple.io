<?hh // strict
use XHPRoot;
class :cms:layout extends :decouple:ui:base {
  protected function compose() : XHPRoot {
    return <layouts:front>
      <div class="grid">
        <div class="column-lg-2 column-sm-3 column-xs-6">
          <cms:navigation></cms:navigation>
        </div>
        <div class="column-lg-10 column-sm-9 column-xs-6">
          {$this->getChildren()}
        </div>
      </div>
    </layouts:front>;
  }
}
