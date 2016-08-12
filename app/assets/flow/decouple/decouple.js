/* @flow */

import DecoupleDOM from './dom.js'
import Decoupler from './decoupler.js'
import DecoupleHTTP from './http.js'

const Decouple = {
  dom: new DecoupleDOM(),
  decoupler: new Decoupler(),
  http: new DecoupleHTTP(),
  decouplerCallsign: '$$',
  httpCallsign: '$http'
};

export default Decouple;

window[Decouple.decouplerCallsign] = Decouple.decoupler;
window[Decouple.httpCallsign] = Decouple.http;
