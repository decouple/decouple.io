<?hh // strict
namespace Test\Events;
use Decouple\Test\TestCase;
use Decouple\CLI\Console;
use Decouple\Events\Listener;
use Decouple\Events\Emitter;
use Decouple\Events\Event;
use Test\Events\Fixture\TestEmitter;

class EventsTest extends TestCase {
  private int $emitCount = 0;
  public function execute() : void {
    Console::output('Testing event listeners & emitters');

    $listener = new Listener();
    $listener->on('test', function(Event $event, Vector<mixed> $args) : void {
      $this->assertEquals($event->name, 'test');
      $this->assertEquals($args->at(0), 'Something extra');
      $this->increment();
    });

    $emitter = new TestEmitter($listener);
    $emitter->emit('test', Vector{'Something extra'});
    $emitter->emit('test', Vector{'Something extra'});
    $emitter->emit('test', Vector{'Something extra'});

    $this->assertEquals($this->emitCount, 3);
  }

  public function increment() : void {
    $this->emitCount++;
  }
}
