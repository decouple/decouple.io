/* @flow */
import $$ from './decouple/decouple.js'
import LinkDirective from './directives/link.js'

$$.dom.registerDirective(LinkDirective);
$$.dom.bootstrap();
