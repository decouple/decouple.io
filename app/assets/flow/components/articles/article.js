/* @flow */

import React from 'react'

export default class Article extends React.Component {
  constructor(props) {
    super(props);
  }

  render() {
    return (
      <div className="item">
        <div className="ui large rounded image">
          <img src={this.props.article.image} />
          <a className="like ui corner label">
            <i className="like icon"></i>
          </a>
        </div>
        <h4 className="header"></h4>
        <div className="content">
          <div className="name">{this.props.article.title}</div>
          <p className="description">{this.props.article.content}</p>
          <div className="extra">{this.props.article.date}</div>
        </div>
      </div>
    );
  }
}
