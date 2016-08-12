<?hh // decl
use Decouple\Common\Contract\DB\Schema;
class :layouts:header extends :decouple:ui:base {
  attribute
    Schema schema @required,
    string title @required;

  public function compose() {
    return
      <header>
        <h1>{$this->getAttribute('title')}</h1>
        <navigation:horizontal schema={$this->getAttribute('schema')}/>
      </header>
    ;
  }
}
