<?hh // partial
use Decouple\Singleton\Router;
Router::get("/", "FrontController@index");

Router::restful("/news", "NewsController");
Router::restful("/admin/news", "Admin\NewsController");
