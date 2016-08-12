Decouple Framework
=========
An attempt to create a loosely coupled toolkit for Hack.
Based loosely on Laravel.

## Installation
```composer create-project decouple/framework=dev-master```
##### OR
```git clone gogs@git.phenocode.com:decouple/framework.git```

## Getting Started
The application is bootstrapped by the scripts in `bootstrap/`.  
For now, check the bootstrap scripts to get a better understanding of how Decouple works.

Models are stored in `app/database/models`.  
Views are stored in `app/views` and are based on `facebook/xhp-lib`.  
Controllers are stored in `app/controllers`.  
Seeds are stored in `app/database/seeds`.  
Migrations are stored in `app/database/migrations`.  
Commands are stored in `app/database/commands`.

The DBAL and Command Runner supports async.
