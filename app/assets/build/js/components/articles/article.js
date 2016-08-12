import React from 'react';

export default class Article extends React.Component {
  constructor(props) {
    super(props);
  }

  render() {
    return React.createElement(
      "div",
      { className: "item" },
      React.createElement(
        "div",
        { className: "ui large rounded image" },
        React.createElement("img", { src: this.props.article.image }),
        React.createElement(
          "a",
          { className: "like ui corner label" },
          React.createElement("i", { className: "like icon" })
        )
      ),
      React.createElement("h4", { className: "header" }),
      React.createElement(
        "div",
        { className: "content" },
        React.createElement(
          "div",
          { className: "name" },
          this.props.article.title
        ),
        React.createElement(
          "p",
          { className: "description" },
          this.props.article.content
        ),
        React.createElement(
          "div",
          { className: "extra" },
          this.props.article.date
        )
      )
    );
  }
}