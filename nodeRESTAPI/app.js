'use strict';
//Config
var config 		= 	require('./config');

//Modules
var express 	= 	require('express'),
	app 		= 	express(),
	port 		= 	process.env.PORT || config.PORT,
	mongoose 	= 	require('mongoose'),
  	bodyParser 	= 	require('body-parser');

//Models
var	Task 		= 	require('./api/models/todoModel');

mongoose.Promise = global.Promise;

app.use(bodyParser.urlencoded({ extended: true }));
app.use(bodyParser.json());

var routes = require('./api/routes/todoRoutes');
routes(app);

app.listen(port);

console.log('todo list RESTful API server started on: ' + port);
