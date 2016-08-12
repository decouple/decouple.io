<?hh // strict
namespace Decouple\Events;
use Decouple\Decoupler\Decoupler;

type EventCallback = (function(Event, ...):bool);
class Listener {
  protected Map<string,Vector<(function(Event, Vector<mixed>) : void)>> $registry;

  public function __construct() {
    $this->registry = Map {};
  }

  /**
   * Listen for an event, and when it is triggered call the given callback
   */
  public function on(string $event, (function(Event, Vector<mixed>) : void) $callable) : void {
    if(!$this->registry->contains($event)) {
      $this->registry->add(Pair {$event, Vector { $callable }});
    } else {
      $entry = $this->registry->get($event);
      if($entry !== null) {
        $entry->add($callable);
      }
    }
  }

  /**
   * Notify the listener that an event has been triggered
   */
  public function notify(string $event, ...) : bool {
    $args = func_get_args();
    array_shift($args);
    array_unshift($args, new Event($event));
    if($this->registry->contains($event)) {
      $event_callbacks = $this->registry->at($event);
      foreach($event_callbacks as $callback) {
        call_user_func_array($callback, $args);
      }
      return true;
    }
    return false;
  }
}
