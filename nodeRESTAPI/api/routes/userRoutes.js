'use strict';

module.exports = function(app) {
  var user = require('../controllers/userController');

  app.route('/register')
    .post(user.registerUser);

  app.route('/login')
    .get(user.login);
};