<?hh // strict
namespace Decouple\Singleton;
class Router {
  private static ?\Decouple\HTTP\Router\Router $_instance;
  public static function instance() {
    if(static::$_instance) {
      return static::$_instance;
    }
    static::$_instance = new \Decouple\HTTP\Router\Router(Decoupler::instance());
    return static::$_instance;
  }
  public static function serve(string $type, string $pattern, mixed $function=null) : int {
    return static::instance()->serve($type, $pattern, $function);
  }
  public static function add(RouteInterface $route) : void {
    return static::instance()->add($route);
  }
  public static function fetch(int $id) : AbstractRoute {
    return static::instance()->fetch($id);
  }
  public static function get(string $pattern, mixed $function=null) : int {
    return static::instance()->get($pattern, $function);
  }
  public static function post(string $pattern, mixed $function=null) : int {
    return static::instance()->post($pattern, $function);
  }
  public static function delete(string $pattern, mixed $function=null) : int {
    return static::instance()->delete($pattern, $function);
  }
  public static function options(string $pattern, mixed $function=null) : int {
    return static::instance()->options($pattern, $function);
  }
  public static function put(string $pattern, mixed $function=null) : int {
    return static::instance()->put($pattern, $function);
  }
  public static function head(string $pattern, mixed $function=null) : int {
    return static::instance()->head($pattern, $function);
  }
  public static function restful(string $pattern, mixed $function=null) : int {
    return static::instance()->restful($pattern, $function);
  }
  public static function group(Map<string,mixed> $options, Vector<Pair<string,Pair<string,mixed>>> $routes) : void {
    return static::instance()->group($options, $routes);
  }
  public static function route(Request $request) : mixed {
    return static::instance()->route($request);
  }
}
