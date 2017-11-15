'use strict';
//Modules
var   mongoose  =   require('mongoose'),
      
//Schema
var   Schema    =   mongoose.Schema;

var UserSchema = new Schema({
  username: {
    type: String,
    required: 'Please enter a username.'
  },
  password: {
    type: String,
    required: 'Please enter a password.'
  },
  isAdmin: {
    type: Boolean,
    default: false
  }
}, { versionKey: false });

module.exports = mongoose.model('User', UserSchema);