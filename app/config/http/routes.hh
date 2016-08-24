<?hh // partial
use Decouple\Singleton\Router;
Router::get("/", "FrontController@index");

Router::restful("/news", "NewsController");
Router::restful("/admin/cms/articles", "Admin\ArticlesController");
Router::restful("/admin/cms", "Admin\CMSController");
