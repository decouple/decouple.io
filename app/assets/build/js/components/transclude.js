import { h, Component } from 'preact';

export default class Transclude extends Component {
  constructor(props) {
    super(props);
  }

  render() {
    return h("div", { className: "transclude" });
  }
}