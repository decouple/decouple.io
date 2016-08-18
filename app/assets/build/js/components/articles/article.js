import { h, Component } from 'preact';

export default class Article extends Component {
  constructor(props) {
    super(props);
  }

  render() {
    return h(
      "div",
      { className: "item" },
      h(
        "div",
        { className: "ui large rounded image" },
        h("img", { src: this.props.article.image }),
        h(
          "a",
          { className: "like ui corner label" },
          h("i", { className: "like icon" })
        )
      ),
      h("h4", { className: "header" }),
      h(
        "div",
        { className: "content" },
        h(
          "div",
          { className: "name" },
          this.props.article.title
        ),
        h(
          "p",
          { className: "description" },
          this.props.article.content
        ),
        h(
          "div",
          { className: "extra" },
          this.props.article.date
        )
      )
    );
  }
}