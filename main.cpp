#include <iostream>
#include "src/TodoList.hpp"

int main() {
    TodoList myTodos;
    
    std::cout << "Simple Todo List Application" << std::endl;
    
    std::cout << std::endl << "Adding tasks to the list..." << std::endl;
    myTodos.add("Buy groceries");
    myTodos.add("Complete CSC 122 assignment");
    myTodos.add("Walk the dog");
    myTodos.add("Read a book");
    myTodos.add("Exercise for 30 minutes");
    
    myTodos.all();
    
    std::cout << std::endl << "Marking some tasks as complete..." << std::endl;
    myTodos.complete(1);
    myTodos.complete(3);
    
    myTodos.all();
    myTodos.completed();
    myTodos.incomplete();
    
    std::cout << std::endl << "Adding another task..." << std::endl;
    myTodos.add("Call mom");
    
    myTodos.all();
    
    std::cout << std::endl << "Completing more tasks..." << std::endl;
    myTodos.complete(0);
    myTodos.complete(2);
    
    myTodos.completed();
    myTodos.incomplete();
    
    std::cout << std::endl << "Total tasks: " << myTodos.size() << std::endl;
    std::cout << "Completed: " << myTodos.getCompletedTasks().size() << std::endl;
    std::cout << "Incomplete: " << myTodos.getIncompleteTasks().size() << std::endl;
    
    std::cout << std::endl << "Clearing all tasks..." << std::endl;
    myTodos.clear();
    
    myTodos.all();
    
    return 0;
}