var gulp = require('gulp'),
    notify = require('gulp-notify'),
    babel = require('gulp-babel'),
    flow = require('gulp-flowtype'),
    sourcemaps = require('gulp-sourcemaps'),
    sourcemapReporter = require('jshint-sourcemap-reporter'),
    browserify = require("browserify"),
    fs = require("fs"),
    sass = require("gulp-sass"),
    autoprefixer = require("gulp-autoprefixer"),
    jsmin = require('gulp-jsmin'),
    cssmin = require('gulp-cssmin'),
    source = require('vinyl-source-stream'),
    buffer = require('vinyl-buffer'),
    del = require('del'),
    browserSync = require('browser-sync').create();

var clientSrcDir = "app/assets",
  flowDest = "app/assets/build/js",
  buildDest = "public/assets",
  viewDir = "app/views";

gulp.task('sync', ['build','sass','fonts'], function() {
    browserSync.init({
      proxy: 'decouple.app'
    });
    gulp.watch(viewDir + '/**/*.hh').on('change', browserSync.reload);
    gulp.watch(clientSrcDir + '/sass/**/*.scss', ['sass']);
    gulp.watch(clientSrcDir + '/sass/**/*.js', ['build'])
      .on('change', browserSync.reload);;
});

gulp.task('fonts', function(cb) {
  gulp.src('./node_modules/mdi/fonts/**/*.{eot,svg,ttf,woff,woff2}')
    .pipe(gulp.dest(buildDest + '/fonts'))
    .on('end', cb);
});

gulp.task('flow:babel', function(cb) {
  buildPreFlow(cb);
});

gulp.task('flow:check', ['flow:babel'], function(cb) {
  buildFlow(cb);
});

gulp.task('flow:watch', function() {
  gulp.watch(clientSrcDir + '/flow/**/*.js', ['flow:check']);
});

gulp.task('default', function() {
  gulp.start('fonts');
  gulp.start('build');
  gulp.start('sass');
});

gulp.task('build', ['clean'], function(cb) {
  buildPreFlow(function() {
    buildFlow(function() {
      buildBrowserify(cb);
    })
  });
});

gulp.task('clean-sass', function() {
  del([buildDest + '/css/*.css']);
});

gulp.task('clean', function() {
  del([ buildDest + '/js/*.js']);
});

gulp.task('sass', ['clean-sass'], function(cb) {
  return buildSass(cb);
});

gulp.task('watch', function() {
  gulp.watch(clientSrcDir + '/flow/**/*.js', ['build']);
  gulp.watch(clientSrcDir + '/sass/**/*.scss', ['sass']);
});

function buildFlow(cb) {
  return gulp.src(flowDest + '/**/*.js')
    .pipe(flow({
        all: false,
        weak: false,
        killFlow: true,
        beep: true,
        abort: false
    }))
    .on('end', cb);
}

function buildPreFlow(cb) {
  return gulp.src(clientSrcDir + '/flow/**/*.js')
    .pipe(babel({"presets": ["react"], "plugins": ["syntax-flow", ["transform-react-jsx", { "pragma": "h" }]]}))
    .on('error', notify.onError('<%= error.message %>'))
    .pipe(gulp.dest(flowDest))
    .on('end', cb);
}

function buildBrowserify(cb) {
  return browserify(flowDest + "/app.js")
    .transform("babelify", {presets: ["es2015"], plugins: ["transform-flow-strip-types", "transform-class-properties"]})
    .on('error', function (error) {
      console.log('Error', error.message);
      this.emit('end');
    })
    .bundle()
    .pipe(source('bundle.js'))
    .pipe(buffer())
    // .pipe(sourcemaps.init())
    .pipe(jsmin())
    // .pipe(sourcemaps.write())
    .pipe(gulp.dest(buildDest + "/js/"))
    .on('end', cb);
}

function buildSass(cb) {
  return gulp.src(clientSrcDir + '/sass/**/*.scss')
    // .pipe(sourcemaps.init())
    .pipe(sass().on('error', sass.logError))
    // .pipe(sourcemaps.write())
    .pipe(autoprefixer())
    .pipe(cssmin())
    .pipe(gulp.dest(buildDest + "/css"))
    .pipe(browserSync.stream());
}
