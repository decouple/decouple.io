<?hh // strict
namespace Test\Events\Fixture;
use Decouple\Events\Listener;
use Decouple\Events\Emitter;

class TestEmitter extends Emitter {
  public function __construct(Listener $listener) {
    parent::__construct($listener);
  }
}
