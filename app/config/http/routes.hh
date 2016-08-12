<?hh // partial
use API\TestController;
return Map {
  "/" => "FrontController@index",
  "/news/(.*)" => "NewsController",
  "/test" => "FrontController@test",
  "/api/test/(.*)" => TestController::class
};
