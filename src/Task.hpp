#pragma once

#include <string>

class Task {
public:
    Task(std::string description);
    
    const std::string& getDescription() const;
    bool isComplete() const;
    void markComplete();
    
private:
    std::string description;
    bool completed;
};

