<?hh // partial
use Decouple\Singleton\Router;
Router::get("/", "FrontController@index");
Router::restful("/news/(.*)", "NewsController");
