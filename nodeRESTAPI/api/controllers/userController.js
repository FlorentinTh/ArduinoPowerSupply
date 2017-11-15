'use strict';
//Config
var db               =   require('../../modules/db');
// Modules
var mongoose         =   require('mongoose'),
	jwt 			 = 	 require('jsonwebtoken');
	bcrypt    		 =   require('bcryptjs');
// Model
var User             =   db.model('User');
//Handlers
var errorHandler     =   require('../errors/errorHandler.js');



exports.registerUser = function(req, res) {
  var hashedPassword = bcrypt.hashSync(req.body.password, 8);
  var newuser = new User(req.body.username, hashedPassword, req.body.isAdmin);
  newuser.save().then(function(user) {
     res.status(201).json(user);
  }).catch(function(err) {
    errorHandler.error(res, err.message, "Failed to register the user.");
  });
};