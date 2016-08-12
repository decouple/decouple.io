/* @flow */

export default class Decoupler {
  injectables : Object;

  constructor() {
    this.injectables = {};
  }

  inject(injected : Array<string>, thing : mixed) {
    if(thing instanceof Object) {
      return this.injectObject(injected, thing);
    } else if(typeof(thing) == 'function') {
      return this.injectMethod(injected, thing);
    }
  }

  injectObject(injected : Array<string>, obj : Object) {
    injected.forEach((name) => {
      obj[name] = this.getInjectable(name);
    });
  }

  injectMethod(injected : Array<string>, callback : mixed) {
    if(typeof(callback) == 'function') {
      return callback.call(...this.getInjectables(injected));
    }
  }

  getInjectable(name : string) {
    if(this.injectables.hasOwnProperty(name)) {
      return this.injectables[name];
    }
    return false;
  }

  getInjectables(names : Array<string>) {
    let injecting = [];
    names.forEach((name) => {
      injecting.push(this.getInjectable(name));
    });
    return injecting;
  }

  promise(thing : mixed) : mixed {
    if(typeof thing == 'function') {
      return new Promise(thing);
    }
  }
}
