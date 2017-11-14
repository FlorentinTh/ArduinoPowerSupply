var mongoose = require('mongoose');

var HOST 	= 	'localhost';
var DBNAME 	= 	'Todo';

var db = mongoose.createConnection('mongodb://' + HOST + '/' + DBNAME);

db.on('error', function(err) {
	if (err) {
		throw err;
	}
});

db.once('open', function() {
	console.info('Successfully connected to Mongo ' + DBNAME + ' database');
});

module.exports = db;