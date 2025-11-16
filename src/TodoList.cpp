#include "TodoList.hpp"
#include <iostream>

bool TodoList::add(const std::string& description) {
    if (description.empty() || description.find_first_not_of(' ') == std::string::npos) {
        return false;
    }
    
    for (int i = 0; i < tasks.size(); i++) {
        if (tasks[i].getDescription() == description && !tasks[i].isComplete()) {
            return false;
        }
    }
    
    Task newTask(description);
    tasks.push_back(newTask);
    return true;
}

bool TodoList::complete(int index) {
    if (index < 0 || index >= tasks.size()) {
        return false;
    }
    tasks[index].markComplete();
    return true;
}

void TodoList::all() const {
    std::cout << std::endl << "To Do" << std::endl;
    if (tasks.empty()) {
        std::cout << "Done for the day!" << std::endl;
        return;
    }
    for (int i = 0; i < tasks.size(); i++) {
        std::cout << "  [" << (tasks[i].isComplete() ? "X" : " ") << "] " 
                  << i + 1 << ". " << tasks[i].getDescription() << std::endl;
    }
}

void TodoList::completed() const {
    std::cout << std::endl << "Completed Tasks" << std::endl;
    bool hasCompleted = false;
    for (int i = 0; i < tasks.size(); i++) {
        if (tasks[i].isComplete()) {
            std::cout << "  [X] " << i + 1 << ". " << tasks[i].getDescription() << std::endl;
            hasCompleted = true;
        }
    }
    if (!hasCompleted) {
        std::cout << "Done for the day!" << std::endl;
    }
}

void TodoList::incomplete() const {
    std::cout << std::endl << "Incomplete Tasks" << std::endl;
    bool hasIncomplete = false;
    for (int i = 0; i < tasks.size(); i++) {
        if (!tasks[i].isComplete()) {
            std::cout << "  [ ] " << i + 1 << ". " << tasks[i].getDescription() << std::endl;
            hasIncomplete = true;
        }
    }
    if (!hasIncomplete) {
        std::cout << "Done for the day!" << std::endl;
    }
}

std::vector<Task> TodoList::getAllTasks() const {
    return tasks;
}

std::vector<Task> TodoList::getCompletedTasks() const {
    std::vector<Task> result;
    for (int i = 0; i < tasks.size(); i++) {
        if (tasks[i].isComplete()) {
            result.push_back(tasks[i]);
        }
    }
    return result;
}

std::vector<Task> TodoList::getIncompleteTasks() const {
    std::vector<Task> result;
    for (int i = 0; i < tasks.size(); i++) {
        if (!tasks[i].isComplete()) {
            result.push_back(tasks[i]);
        }
    }
    return result;
}

void TodoList::clear() {
    tasks.clear();
}

int TodoList::size() const {
    return tasks.size();
}

bool TodoList::empty() const {
    return tasks.empty();
}

