<?hh // partial
return Map {
  "default" => Map {
    "params" => Map {
      "type" => "mysql",
      "host" => "127.0.0.1"
    },
    "schema" => "decouple",
    "user" => "homestead",
    "password" => "secret"
  },
  "test" => Map {
    "params" => Map {
      "type" => "mysql",
      "host" => "127.0.0.1"
    },
    "schema" => "decouple_test",
    "user" => "homestead",
    "password" => "secret"
  }
};
