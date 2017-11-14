'use strict';

module.exports = function(app) {
  var todo = require('../controllers/todoController');

  app.route('/api/tasks')
    .get(todo.getTasks)
    .post(todo.addTask);

  app.route('/api/tasks/:taskId')
    .get(todo.getTask)
    .put(todo.editTask)
    .delete(todo.deleteTask);
};