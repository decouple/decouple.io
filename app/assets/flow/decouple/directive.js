import Decouple from './decouple.js';

export default class Directive {
  object : scope;
  array : children;

  constructor(scope) {
    this.scope = scope;
    this.children = [];
  }

  __render() : string {
    if(this.render) {
      let res = this.render();
      if(typeof(res) == 'string') {
        return Decouple.dom.stringToNode(res, "text/html");
      } else {
        return res;
      }
    }
    throw "A Decouple Directive must declare a render() method";
  }
}
