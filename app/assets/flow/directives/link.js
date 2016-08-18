import Directive from '../decouple/directive.js'
import Transclude from '../components/transclude.js'
import {h} from 'preact'
/** @jsx h */

export default class LinkDirective extends Directive {
  transclude : bool;
  constructor(scope) {
    super(scope);
    this.transclude = true;
  }

  static get attribute() : string {
    return "link";
  }

  static get injects() : array {
    return ['NewsResource'];
  }

  static get scoped() : array {
    return ['link'];
  }

  render() : void {
    return <a href={this.scope.get('link')}><Transclude /></a>;
  }

  onClick($event) : void {
    $event.stopPropagation();
    $event.preventDefault();
  }

  onMouseOver($event) : void {
    console.log('Mouse over');
  }

  onMouseOut($event) : void {
    console.log('Mouse out');
  }
}
