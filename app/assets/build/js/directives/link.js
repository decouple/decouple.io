import Directive from '../decouple/directive.js';
import Transclude from '../components/transclude.js';
import { h } from 'preact';
/** @jsx h */

export default class LinkDirective extends Directive {
  constructor(scope) {
    super(scope);
    this.transclude = true;
  }

  static get attribute() {
    return "link";
  }

  static get injects() {
    return ['NewsResource'];
  }

  static get scoped() {
    return ['link'];
  }

  render() {
    return h(
      'a',
      { href: this.scope.get('link') },
      h(Transclude, null)
    );
  }

  onClick($event) {
    $event.stopPropagation();
    $event.preventDefault();
  }

  onMouseOver($event) {
    console.log('Mouse over');
  }

  onMouseOut($event) {
    console.log('Mouse out');
  }
}