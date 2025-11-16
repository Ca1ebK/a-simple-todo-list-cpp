#include <iostream>
#include "src/TodoList.hpp"

void displayTasks(const std::vector<Task>& tasks, const std::string& title="To Do") {
    std::cout << std::endl << title << std::endl;
    
    if (tasks.empty()) {
        std::cout << "Done for the day!" << std::endl;
        return;
    }
    
    for (int i = 0; i < tasks.size(); i++) {
        std::cout << "  [" << (tasks[i].isComplete() ? "X" : " ") << "] " 
                  << i + 1 << ". " << tasks[i].getDescription() << std::endl;
    }
}

int main() {
    TodoList myTodos;
    
    std::cout << "Simple Todo List Application" << std::endl;
    
    std::cout << std::endl << "Adding tasks to the list..." << std::endl;
    myTodos.add("Buy groceries");
    myTodos.add("Complete CSC 122 assignment");
    myTodos.add("Walk the dog");
    myTodos.add("Read a book");
    myTodos.add("Exercise for 30 minutes");
    
    displayTasks(myTodos.all());
    
    std::cout << std::endl << "Marking some tasks as complete..." << std::endl;
    myTodos.complete(1);
    myTodos.complete(3);
    
    displayTasks(myTodos.all());
    displayTasks(myTodos.completed(), "Completed Tasks");
    displayTasks(myTodos.incomplete(), "Incomplete Tasks");
    
    std::cout << std::endl << "Adding another task..." << std::endl;
    myTodos.add("Call mom");
    
    displayTasks(myTodos.all());
    
    std::cout << std::endl << "Completing more tasks..." << std::endl;
    myTodos.complete(0);
    myTodos.complete(2);
    
    displayTasks(myTodos.completed(), "Completed Tasks");
    displayTasks(myTodos.incomplete(), "Incomplete Tasks");
    
    std::cout << std::endl << "Total tasks: " << myTodos.size() << std::endl;
    std::cout << "Completed: " << myTodos.completed().size() << std::endl;
    std::cout << "Incomplete: " << myTodos.incomplete().size() << std::endl;
    
    std::cout << std::endl << "Clearing all tasks..." << std::endl;
    myTodos.clear();
    
    displayTasks(myTodos.all());

    return 0;
}