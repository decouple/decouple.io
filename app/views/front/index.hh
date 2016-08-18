<?hh // strict
use Decouple\Common\Contract\DB\Schema;
class :front:index extends :decouple:ui:base {
  attribute
    Schema schema @required,
    string title @required;

  public function compose(): XHPRoot {
    return
      <layouts:front schema={$this->getAttribute('schema')} title={$this->getAttribute('title')}>
        <div>
          <h2 class="ui large dividing header">Frontpage</h2>
          {$this->getChildren()}
        </div>
      </layouts:front>
    ;
  }
}
