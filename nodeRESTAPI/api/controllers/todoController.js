'use strict';

var mongoose         =   require('mongoose'),
    db               =   require('../../modules/db'),
    Task             =   db.model('Tasks'),
    errorHandler     =   require('../errors/errorHandler.js');


exports.getTasks = function(req, res) {
  Task.find({}).then(function(tasks) {
    res.status(200).json(tasks);
  }).catch(function(err) {
    errorHandler.error(res, err.message, "Failed to get tasks");
  });
};

exports.addTask = function(req, res) {
  var newTask = new Task(req.body);
  newTask.save().then(function(task) {
     res.status(201).json(task);
  }).catch(function(err) {
    errorHandler.error(res, err.message, "Failed to create new task.");
  });
};

exports.getTask = function(req, res) {
  Task.findById(req.params.taskId).then(function(task) {
    res.status(200).json(task);
  }).catch(function(err) {
    errorHandler.error(res, err.message, "Task not found", 404);
  });
};

exports.editTask = function(req, res) {
  Task.findOneAndUpdate({_id: req.params.taskId}, req.body, {new: true}).then(function(task) {
    res.status(200).json(task);
  }).catch(function(err) {
   errorHandler.error(res, err.message, "Task not found", 404);
  });
};

exports.deleteTask = function(req, res) {
  Task.remove({_id: req.params.taskId}).then(function(task) {
    res.status(200).json({ message: 'Task successfully deleted' });
  }).catch(function(err) {
    errorHandler.error(res, err.message, "Task not found", 404);
  });
};