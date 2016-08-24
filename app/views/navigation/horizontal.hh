<?hh // strict
use Decouple\Common\Contract\DB\Schema;
class :navigation:horizontal extends :x:element {
  use XHPAsync;
  protected async function asyncRender(): Awaitable<XHPRoot> {
    $out =
      <div class="nav">
        <a href="/" class="nav--item">
          <i class="icon icon-home"></i> Home
        </a>
        <a href="/news" class="nav--item">
          <i class="icon icon-newspaper"></i> News
        </a>
        <div class="nav--item__dropdown">
          <a href="/admin/dashboard">
            <i class="icon icon-account-key"></i> Admin
          </a>
          <ul>
            <li>
              <a href="/admin/dashboard">
                <i class="icon icon-speedometer"></i> Dashboard
              </a>
            </li>
            <li>
              <a href="/admin/cms">
                <i class="icon icon-book-open-page-variant"></i> Content
              </a>
            </li>
            <li>
              <a href="/admin/users">
                <i class="icon icon-account-multiple-plus"></i> Users
              </a>
            </li>
            <li>
              <a href="/admin/docs">
                <i class="icon icon-file-document"></i> Documentation
              </a>
            </li>
          </ul>
        </div>
        <div class="pull-right">
          <a href="/register" class="nav--item">
            <i class="icon icon-lead-pencil"></i> Register
          </a>
          <a href="/login" class="nav--item">
            <i class="icon icon-lock-open"></i> Log In
          </a>
        </div>
        <div class="clearfix"></div>
      </div>
    ;
    return $out;
  }
}
