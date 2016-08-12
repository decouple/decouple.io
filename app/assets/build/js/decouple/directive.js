import React from 'react';
import Decouple from './decouple.js';

export default class Directive {

  constructor(options) {
    this.options = options;
  }

  __render() {
    if (this.boot) {
      let res = this.boot();
      if (typeof res == 'string') {
        return Decouple.dom.stringToNode(res, "text/html");
      } else {
        return res;
      }
    }
    throw "A Decouple Directive must declare a boot() method";
  }
}