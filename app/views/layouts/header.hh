<?hh // decl
use Decouple\Common\Contract\DB\Schema;
class :layouts:header extends :decouple:ui:base {
  attribute
    Schema schema @required,
    string title @required;

  protected function compose() : XHPRoot {
    return
      <header>
        <h1>{$this->getAttribute('title')}</h1>
        <navigation:horizontal schema={$this->getAttribute('schema')}/>
      </header>
    ;
  }
}
