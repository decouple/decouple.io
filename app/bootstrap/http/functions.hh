<?hh // strict
function http_error_handler(int $errno, string $errstr, string $errfile, int $errline) : void {
  echo sprintf("[ERROR#%s] %s on line %s of %s\n", $errno, $errstr, $errline, $errfile);
}

function http_exception_handler(Exception $e) : void {
  $body =
  <div>
    <h1>Exception</h1>
    <p class="ui error message">{$e->getMessage()}</p>
  </div>
  ;
  $errors =
  <table>
    <thead>
      <tr>
        <th>File</th><th>Line</th><th>Function</th><th>Arguments</th>
      </tr>
    </thead>
  </table>
  ;
  $errors->addClass('ui table');
  $tbody = <tbody/>;
  $trace = $e->getTrace();
  foreach($trace as $p) {
    $p = new Map($p);
    try {
      $file = $p->contains('file') ? $p['file'] : 'N/A';
      $args = $p->contains('args') ? json_encode($p['args']) : 'N/A';
      $func = $p->contains('class') ? sprintf('%s->%s', $p['class'], $p['function']) : ($p->contains('function') ? $p['function'] : 'N/A');
      $line = $p->contains('line') ? $p['line'] : 'N/A';
      $error =
      <tr>
        <td>{$file}</td>
        <td>{$line}</td>
        <td>{$func}</td>
        <td>{$args}</td>
      </tr>
      ;
      $tbody->appendChild($error);
    } catch(Exception $e) {}
  }
  $errors->appendChild($tbody);
  $body->appendChild($errors);
  echo $body;
}
