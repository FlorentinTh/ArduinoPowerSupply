'use strict';
//Config
var config 	 = 	require('./config');
//Modules
var mongoose = 	require('mongoose');

var db = mongoose.createConnection('mongodb://' + config.HOST + '/' + config.DB);

db.on('error', function(err) {
	if (err) {
		throw err;
	}
});

db.once('open', function() {
	console.info('Successfully connected to Mongo ' + config.DB + ' database');
});

module.exports = db;