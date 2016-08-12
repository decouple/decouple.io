export default class DecoupleHTTP {
  constructor() {

  }
  request(method : string, url : string, json : bool) : Promise {
    return new Promise((resolve, reject) => {
      let xhr = new XMLHttpRequest();
      xhr.open(method, url)
      xhr.onload = (e) => {
        if(e.currentTarget.status >= 200 && e.currentTarget.status < 300) {
          resolve(json ? JSON.parse(xhr.response) : xhr.response);
        } else {
          reject({
            status: e.currentTarget.status,
            statusText: xhr.statusText
          });
        }
      }
      xhr.onError = (e) => {
        reject({
          status: e.currentTarget.status,
          statusText: xhr.statusText
        });
      };
      xhr.send();
    });
  }
}
