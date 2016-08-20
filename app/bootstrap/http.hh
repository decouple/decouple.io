<?hh // partial
require_once "http/functions.hh";

// Error handling
set_exception_handler('http_exception_handler');
set_error_handler('http_error_handler', E_ERROR);

require_once "common.hh";

use Decouple\HTTP\Request\Uri;
use Decouple\HTTP\Request\Request;
use Decouple\Registry\Registry;
use Decouple\Registry\Paths;
use Decouple\Ui\Ui;
use Decouple\Log\Log;
use Decouple\HTTP\App;

use Decouple\Singleton\Router;
use Decouple\Singleton\Decoupler;

// Http request
$type = $_SERVER['REQUEST_METHOD'];
$uri = new Uri($_SERVER['REQUEST_URI']);
$get = new Map($_GET);
$post = new Map($_POST);
$files = new Map($_FILES);
$request = new Request($uri, $get, $post, $files, $type);

// Register HTTP-specific services
Decoupler::set('Decouple\HTTP\Request\Request', $request);
Decoupler::set('Decouple\HTTP\Request\Uri', $uri);

// Bootstrap routes
hack_require($base_dir.'/app/config/http/routes.hh');

// Http application
$app = new App($request, Router::instance(), Decoupler::instance());

// Register map of http services
$http_services = Map {};
$app->addServices($http_services);

// Add a single route
$app->addRoute(
  "GET",
  "/version",
  function (Ui $ui, Log $log, DebugRegistry $debug) {
    return
      <layouts:front>
        <h1>
          Version
        </h1>
        <p class="segment">
          Decouple v0.1a
        </p>
        <p class="segment">
          HHVM v{HHVM_VERSION}
        </p>
        {perf_info($debug)}
      </layouts:front>;
  },
);
