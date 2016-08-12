<?hh // strict
use XHPRoot;
class :layouts:front extends :layouts:master {
  attribute
    string title @required;
  public function compose() : XHPRoot {
    $this->setTitle('Decouple | Home');
    $this->addStyle('main', '/assets/css/app.css');
    $this->addScript('bundle', '/assets/js/bundle.js');
    $this->prependChild(<layouts:header schema={$this->getAttribute('schema')} title={$this->getAttribute('title')}/>);
    $this->appendChild(<div id="app" />);
    return parent::compose();
  }
}
