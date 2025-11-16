#include "Task.hpp"

Task::Task(std::string description) 
    : description(description), completed(false) {}

const std::string& Task::getDescription() const {
    return description;
}

bool Task::isComplete() const {
    return completed;
}

void Task::markComplete() {
    completed = true;
}

