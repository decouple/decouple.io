import Decouple from '../decouple/decouple.js'

class NewsResource {
  url : string;
  constructor() {
    this.url = '/api/news/:id';
  }

  prepareURL(params : object) : string {
    let parts = this.url.split('/');
    let parsed = [];
    parts.forEach((section : string) => {
      if(section.substr(0, 1) == ':') {
        let varName = section.substr(1);
        if(params[varName]) {
          parsed.push(params[varName]);
        }
      } else {
        parsed.push(section);
      }
    });
    return parsed.join('/');
  }

  get(params : object) : Promise {
    return Decouple.http.request('get', this.prepareUrl(params), params);
  }
}
