import Directive from '../decouple/directive.js';

export default class LinkDirective extends Directive {
  constructor(props) {
    super(props);
    this.prepend = true;
  }

  static get attribute() {
    return "link";
  }

  static get scope() {
    return ['to'];
  }

  boot() {
    return '<a href="/">Link</a>';
  }

  onClick($event) {
    console.log('Link clicked');
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