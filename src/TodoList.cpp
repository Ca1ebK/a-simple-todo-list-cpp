#include "TodoList.hpp"

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

std::vector<Task> TodoList::all() const {
    return tasks;
}

std::vector<Task> TodoList::completed() const {
    std::vector<Task> result;
    for (int i = 0; i < tasks.size(); i++) {
        if (tasks[i].isComplete()) {
            result.push_back(tasks[i]);
        }
    }
    return result;
}

std::vector<Task> TodoList::incomplete() const {
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

