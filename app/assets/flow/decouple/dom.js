/* @flow */
import { render } from 'preact'
export default class DecoupleDOM {
  Map : directives;
  Map : templates;
  Map : events;

  constructor() {
    this.directives = new Map();
    this.templates = new Map();
    this.events = new Map([
      ['onclick', 'onClick'],
      ['onmouseover', 'onMouseOver'],
      ['onmouseout', 'onMouseOut'],
      ['onmousedown', 'onMouseDown'],
      ['onmouseup', 'onMouseUp'],
      ['onkeypress', 'onKeyPress'],
      ['onkeydown', 'onKeyDown'],
      ['onkeyup', 'onKeyUp'],
      ['onchange', 'onChange'],
      ['onload', 'onLoad']
    ]);
  }

  find(selector : string) : array {
    return document.querySelectorAll(selector);
  }

  registerDirective(directive : Directive) {
    this.directives.set(directive.attribute, directive);
  }

  directiveInstance(string : name) : Directive {
    if(this.directives.has(name)) {
      return new this.directives.get(name);
    }
    throw "Invalid directive requested: '" + name + "'";
  }

  bootstrapDirectives() {
    this.directives.forEach((directive) => {
      let elements = this.find('[' + directive.attribute + '],[directive-' + directive.attribute + '],[data-directive-' + directive.attribute + ']');
      elements.forEach((element) => {
        let scope = new Map();
        if(directive.scoped) {
          directive.scoped.forEach((variable) => {
            if(element.hasAttribute(variable)) {
              scope.set(variable, element.getAttribute(variable));
            } else if(element.hasAttribute('directive-' + variable)) {
              scope.set(variable, element.getAttribute('directive-' + variable));
            } else if(element.hasAttribute('data-directive-' + variable)) {
              scope.set(variable, element.getAttribute('data-directive-' + variable));
            } else {
              scope.set(variable, false);
            }
          });
        }

        var instance = new (this.directives.get(directive.attribute))(scope);
        if(instance.wrap) instance.children.push(element);
        let rendered = instance.__render();

        // Get DOM nodes from React elements
        if(rendered.$$typeof || rendered.nodeName) {
          let div = document.createElement('div');
          render(rendered, div);
          if(div.childNodes.length) {
            rendered = div.childNodes[0];
          } else {
            rendered = '';
          }
        }

        // Attach necessary events
        this.events.forEach((method, event) => {
          if(instance[method]) {
            rendered[event] = instance[method];
          }
        });


        // Add to DOM
        if(instance.replace) {
          element.replace(rendered);
        } else if(instance.prepend) {
          element.insertBefore(rendered, element.firstChild);
        } else if(instance.transclude) {
          console.log(rendered);
          let transclude = rendered.querySelector('.transclude');
          if(transclude) {
            element.parentNode.replaceChild(rendered, element);
            rendered.replaceChild(element, transclude);
          } else {
            element.parentNode.replaceChild(rendered, element);
            rendered.appendChild(element);
          }
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

  makeTemplate(name : string, str : string) {
    let template = document.createElement('template');
    template.innerHTML = str;
    this.templates.set(name, template);
    return template;
  }

  stringToNode(str : string) {
    let template = this.makeTemplate("tmp", str);
    return template.content.firstChild;
  }
}
