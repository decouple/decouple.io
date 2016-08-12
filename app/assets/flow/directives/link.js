import Directive from '../decouple/directive.js'

export default class LinkDirective extends Directive {
  prepend : bool;
  constructor(props) {
    super(props);
    this.prepend = true;
  }

  static get attribute() : string {
    return "link";
  }

  static get scope() : array {
    return ['to'];
  }

  boot() : void {
    return '<a href="/">Link</a>';
  }

  onClick($event) : void {
    console.log('Link clicked');
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
