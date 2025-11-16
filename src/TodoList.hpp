#pragma once

#include <vector>
#include <string>
#include "Task.hpp"

class TodoList {
public:
    void add(const std::string& description);
    bool complete(int index);
    
    std::vector<Task> all() const;
    std::vector<Task> completed() const;
    std::vector<Task> incomplete() const;
    
    void clear();
    int size() const;
    bool empty() const;
    
private:
    std::vector<Task> tasks;
};

