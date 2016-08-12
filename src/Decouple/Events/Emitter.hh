<?hh // strict
namespace Decouple\Events;
class Emitter {
  public function __construct(protected Listener $listener) {}

  /**
   * Get the event listener, or create one if none existss
   */
  public function listener() : Listener {
    if(is_null($this->listener)) {
      $this->listener = new Listener();
    } else if($this->listener instanceof Listener) {
      return $this->listener;
    }
    throw new EventException('Invalid listener configuration');
  }

  /**
   * Emit an event message to the listener
   */
  public function emit(string $event, ...) : void {
    $args = func_get_args();
    $this->listener()->notify(...$args);
  }
}
