#include "TodoList.hpp"

void TodoList::add(const std::string& description) {
    Task newTask(description);
    tasks.push_back(newTask);
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

