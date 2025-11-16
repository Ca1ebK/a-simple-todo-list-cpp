#pragma once

#include <vector>
#include <string>
#include "Task.hpp"

class TodoList {
public:
    bool add(const std::string& description);
    bool complete(int index);
    
    void all() const;
    void completed() const;
    void incomplete() const;
    
    void clear();
    int size() const;
    bool empty() const;
    
    std::vector<Task> getAllTasks() const;
    std::vector<Task> getCompletedTasks() const;
    std::vector<Task> getIncompleteTasks() const;
    
private:
    std::vector<Task> tasks;
};

