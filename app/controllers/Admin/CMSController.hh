<?hh // strict
namespace Admin;
use Decouple\Ui\Ui;
use Decouple\Common\Contract\DB\Driver;
use Decouple\Common\Contract\DB\Schema;
use Decouple\HTTP\Request\Uri;
use Decouple\DBAL\Query\Raw;
use Debug\DebugRegistry;

class CMSController {
  public function getIndex(
    Driver $driver,
    Schema $schema,
    DebugRegistry $debug
  ): :xhp {
    return <cms:layout></cms:layout>;
    ;
  }
}
