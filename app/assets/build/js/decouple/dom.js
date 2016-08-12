export default class DecoupleDOM {

  constructor() {
    this.directives = new Map();
    this.templates = new Map();
    this.events = new Map([['onclick', 'onClick'], ['onmouseover', 'onMouseOver'], ['onmouseout', 'onMouseOut'], ['onmousedown', 'onMouseDown'], ['onmouseup', 'onMouseUp'], ['onkeypress', 'onKeyPress'], ['onkeydown', 'onKeyDown'], ['onkeyup', 'onKeyUp'], ['onchange', 'onChange'], ['onload', 'onLoad']]);
  }

  find(selector) {
    return document.querySelectorAll(selector);
  }

  registerDirective(directive) {
    this.directives.set(directive.attribute, directive);
  }

  directiveInstance(string) {
    if (this.directives.has(name)) {
      return new this.directives.get(name);
    }
    throw "Invalid directive requested: '" + name + "'";
  }

  bootstrapDirectives() {
    this.directives.forEach(directive => {
      let elements = this.find('[' + directive.attribute + '],[directive-' + directive.attribute + ']');
      elements.forEach(element => {
        let props = new Map();
        if (directive.scope) {
          directive.scope.forEach(variable => {
            if (element.hasAttribute(variable)) {
              props.set(variable, element.getAttribute(variable));
            } else if (element.hasAttribute('directive-' + variable)) {
              props.set(variable, element.getAttribute('directive-' + variable));
            } else {
              props.set(variable, false);
            }
          });
        }
        var instance = new (this.directives.get(directive.attribute))(props);
        let rendered = instance.__render();

        // Attach necessary events
        this.events.forEach((method, event) => {
          if (instance[method]) {
            rendered[event] = instance[method];
          }
        });

        // Add to DOM
        if (instance.replace) {
          element.replace(rendered);
        } else if (instance.prepend) {
          element.insertBefore(rendered, element.firstChild);
        } else {
          element.appendChild(rendered);
        }
      });
    });
  }

  bootstrap() {
    document.addEventListener("DOMContentLoaded", () => {
      this.bootstrapDirectives();
    });
  }

  makeTemplate(name, str) {
    let template = document.createElement('template');
    template.innerHTML = str;
    this.templates.set(name, template);
    return template;
  }

  stringToNode(str) {
    let template = this.makeTemplate("tmp", str);
    return template.content.firstChild;
  }
}