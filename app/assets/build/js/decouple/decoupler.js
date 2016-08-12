export default class Decoupler {

  constructor() {
    this.injectables = {};
  }

  inject(injected, thing) {
    if (thing instanceof Object) {
      return this.injectObject(injected, thing);
    } else if (typeof thing == 'function') {
      return this.injectMethod(injected, thing);
    }
  }

  injectObject(injected, obj) {
    injected.forEach(name => {
      obj[name] = this.getInjectable(name);
    });
  }

  injectMethod(injected, callback) {
    if (typeof callback == 'function') {
      return callback.call(...this.getInjectables(injected));
    }
  }

  getInjectable(name) {
    if (this.injectables.hasOwnProperty(name)) {
      return this.injectables[name];
    }
    return false;
  }

  getInjectables(names) {
    let injecting = [];
    names.forEach(name => {
      injecting.push(this.getInjectable(name));
    });
    return injecting;
  }

  promise(thing) {
    if (typeof thing == 'function') {
      return new Promise(thing);
    }
  }
}