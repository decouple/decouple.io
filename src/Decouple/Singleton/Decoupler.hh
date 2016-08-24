<?hh // strict
namespace Decouple\Singleton;
use ReflectionObject;
use ReflectionClass;
use ReflectionMethod;
use ReflectionParameter;
use ReflectionFunction;
use Exception;
class Decoupler {
  public static ?\Decouple\Decoupler\Decoupler $instance;
  public static function instance() : \Decouple\Decoupler\Decoupler {
    if(!static::$instance) {
      static::$instance = new \Decouple\Decoupler\Decoupler(Map {});
    }
    return static::$instance;
  }
  public static function setAll(Map<string, mixed> $dependencies, bool $verify = true): void {
    static::instance()->setAll($dependencies, $verify);
  }
  public static function set(string $name, mixed $dependency, bool $verify = true): void {
    static::instance()->set($name, $dependency, $verify);
  }
  public static function contains(string $name): bool {
    return static::instance()->contains($name);
  }
  public static function get(string $name): mixed {
    return static::instance()->get($name);
  }
  public static function getAll(): Map<string, mixed> {
    return static::instance()->getAll();
  }
  public function verifyName(string $name): void {
    static::instance()->verifyName($name);
  }
  public static function injectObject(mixed $object): mixed {
    return static::instance()->injectObject($object);
  }
  public static function injectInstance(string $className): mixed {
    return static::instance()->injectInstance($className);
  }
  public static function injectMethod(mixed $object, string $method): mixed {
    return static::instance()->injectMethod($object, $method);
  }
  public async function awaitInjectMethod(mixed $object, string $method): Awaitable<mixed> {
    return static::instance()->awaitInjectMethod($object, $method);
  }
  public static function injectFunction(mixed $function): mixed {
    return static::instance()->injectFunction($function);
  }
  protected function functionParams(ReflectionFunction $rf): Vector<mixed> {
    return static::instance()->functionParams($rf);
  }
  protected function methodParams(ReflectionMethod $rm): Vector<mixed> {
    return static::instance()->methodParams($rm);
  }
  public static function inject(mixed $target): mixed {
    return static::instance()->inject($target);
  }
  public static function getCaller() : string {
    return static::instance()->getCaller();
  }
}
