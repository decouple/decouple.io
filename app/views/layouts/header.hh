<?hh // decl
use Decouple\Common\Contract\DB\Schema;
class :layouts:header extends :decouple:ui:base {
  protected function compose() : XHPRoot {
    return
      <header>
        <h1 class="m-b-1">Decouple.io</h1>
        <navigation:horizontal />
      </header>
    ;
  }
}
