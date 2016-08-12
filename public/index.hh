<?hh // partial
$start = getrusage();
session_name('decouple');
session_start();
require_once dirname(__FILE__) . '/../app/bootstrap/http.hh';
try {
  echo $app->execute();
} catch(Exception $e) {
  exit($e->getMessage());
}
