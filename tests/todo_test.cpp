#include <catch2/catch_test_macros.hpp>
#include "../src/TodoList.hpp"
#include "../src/Task.hpp"

TEST_CASE("TodoList starts empty") {
    TodoList list;
    
    REQUIRE(list.empty() == true);
    REQUIRE(list.size() == 0);
}

TEST_CASE("Can add one task to the list") {
    TodoList list;
    
    list.add("Buy groceries");
    
    REQUIRE(list.size() == 1);
    REQUIRE(list.empty() == false);
}

TEST_CASE("Added task appears in all tasks") {
    TodoList list;
    list.add("Buy groceries");
    
    std::vector<Task> allTasks = list.getAllTasks();
    
    REQUIRE(allTasks.size() == 1);
    REQUIRE(allTasks[0].getDescription() == "Buy groceries");
}

TEST_CASE("New task is incomplete by default") {
    TodoList list;
    list.add("Buy groceries");
    
    std::vector<Task> incompleteTasks = list.getIncompleteTasks();
    std::vector<Task> completedTasks = list.getCompletedTasks();
    
    REQUIRE(incompleteTasks.size() == 1);
    REQUIRE(completedTasks.size() == 0);
}

TEST_CASE("Can mark a task as complete") {
    TodoList list;
    list.add("Buy groceries");
    
    bool result = list.complete(0);
    
    REQUIRE(result == true);
    REQUIRE(list.getCompletedTasks().size() == 1);
    REQUIRE(list.getIncompleteTasks().size() == 0);
}

TEST_CASE("Can add multiple tasks to the list") {
    TodoList list;
    
    list.add("Task 1");
    list.add("Task 2");
    list.add("Task 3");
    
    REQUIRE(list.size() == 3);
}

TEST_CASE("All tasks appear in correct order") {
    TodoList list;
    list.add("First task");
    list.add("Second task");
    list.add("Third task");
    
    std::vector<Task> allTasks = list.getAllTasks();
    
    REQUIRE(allTasks.size() == 3);
    REQUIRE(allTasks[0].getDescription() == "First task");
    REQUIRE(allTasks[1].getDescription() == "Second task");
    REQUIRE(allTasks[2].getDescription() == "Third task");
}

TEST_CASE("Multiple tasks are incomplete by default") {
    TodoList list;
    list.add("Task 1");
    list.add("Task 2");
    list.add("Task 3");
    
    REQUIRE(list.getIncompleteTasks().size() == 3);
    REQUIRE(list.getCompletedTasks().size() == 0);
}

TEST_CASE("Can complete multiple tasks") {
    TodoList list;
    list.add("Task 1");
    list.add("Task 2");
    list.add("Task 3");
    
    list.complete(0);
    list.complete(1);
    list.complete(2);
    
    REQUIRE(list.getCompletedTasks().size() == 3);
    REQUIRE(list.getIncompleteTasks().size() == 0);
}

TEST_CASE("Can have mix of completed and incomplete tasks") {
    TodoList list;
    list.add("Task 1");
    list.add("Task 2");
    list.add("Task 3");
    list.add("Task 4");
    
    list.complete(0);
    list.complete(2);
    
    REQUIRE(list.getCompletedTasks().size() == 2);
    REQUIRE(list.getIncompleteTasks().size() == 2);
}

TEST_CASE("Completing task with invalid positive index returns false") {
    TodoList list;
    list.add("Task 1");
    
    bool result = list.complete(10);
    
    REQUIRE(result == false);
}

TEST_CASE("Completing task with negative index returns false") {
    TodoList list;
    list.add("Task 1");
    
    bool result = list.complete(-1);
    
    REQUIRE(result == false);
}

TEST_CASE("Completing task on empty list returns false") {
    TodoList list;
    
    bool result = list.complete(0);
    
    REQUIRE(result == false);
}

TEST_CASE("Cannot complete task at index equal to size") {
    TodoList list;
    list.add("Task 1");
    list.add("Task 2");
    
    bool result = list.complete(2);
    
    REQUIRE(result == false);
}

TEST_CASE("Clear removes all tasks") {
    TodoList list;
    list.add("Task 1");
    list.add("Task 2");
    list.add("Task 3");
    
    list.clear();
    
    REQUIRE(list.empty() == true);
    REQUIRE(list.size() == 0);
}

TEST_CASE("Clear removes both completed and incomplete tasks") {
    TodoList list;
    list.add("Task 1");
    list.add("Task 2");
    list.complete(0);
    
    list.clear();
    
    REQUIRE(list.getCompletedTasks().size() == 0);
    REQUIRE(list.getIncompleteTasks().size() == 0);
}

TEST_CASE("Can add tasks after clearing") {
    TodoList list;
    list.add("Old task");
    list.clear();
    
    list.add("New task");
    
    REQUIRE(list.size() == 1);
    REQUIRE(list.getAllTasks()[0].getDescription() == "New task");
}

TEST_CASE("Completed tasks maintain correct descriptions") {
    TodoList list;
    list.add("Buy milk");
    list.add("Walk dog");
    list.complete(1);
    
    std::vector<Task> completedTasks = list.getCompletedTasks();
    
    REQUIRE(completedTasks.size() == 1);
    REQUIRE(completedTasks[0].getDescription() == "Walk dog");
}

TEST_CASE("Incomplete tasks maintain correct descriptions") {
    TodoList list;
    list.add("Buy milk");
    list.add("Walk dog");
    list.add("Read book");
    list.complete(1);
    
    std::vector<Task> incompleteTasks = list.getIncompleteTasks();
    
    REQUIRE(incompleteTasks.size() == 2);
    REQUIRE(incompleteTasks[0].getDescription() == "Buy milk");
    REQUIRE(incompleteTasks[1].getDescription() == "Read book");
}

TEST_CASE("Task completion status persists") {
    TodoList list;
    list.add("Task 1");
    list.complete(0);
    
    std::vector<Task> allTasks = list.getAllTasks();
    
    REQUIRE(allTasks[0].isComplete() == true);
}

TEST_CASE("Task starts incomplete when created") {
    Task task("Test task");
    
    REQUIRE(task.isComplete() == false);
    REQUIRE(task.getDescription() == "Test task");
}

TEST_CASE("Task can be marked complete") {
    Task task("Test task");
    
    task.markComplete();
    
    REQUIRE(task.isComplete() == true);
}

TEST_CASE("Empty string task description is rejected") {
    TodoList list;
    
    bool result = list.add("");
    
    REQUIRE(result == false);
    REQUIRE(list.size() == 0);
}

TEST_CASE("Blank string with spaces is rejected") {
    TodoList list;
    
    bool result = list.add("   ");
    
    REQUIRE(result == false);
    REQUIRE(list.size() == 0);
}

TEST_CASE("Valid task description is accepted") {
    TodoList list;
    
    bool result = list.add("Valid task");
    
    REQUIRE(result == true);
    REQUIRE(list.size() == 1);
}

TEST_CASE("Duplicate incomplete task is rejected") {
    TodoList list;
    list.add("Buy milk");
    
    bool result = list.add("Buy milk");
    
    REQUIRE(result == false);
    REQUIRE(list.size() == 1);
}

TEST_CASE("Duplicate completed task is allowed") {
    TodoList list;
    list.add("Buy milk");
    list.complete(0);
    
    bool result = list.add("Buy milk");
    
    REQUIRE(result == true);
    REQUIRE(list.size() == 2);
}

TEST_CASE("Can add task after completing duplicate") {
    TodoList list;
    list.add("Walk dog");
    list.complete(0);
    list.add("Walk dog");
    
    REQUIRE(list.size() == 2);
    REQUIRE(list.getCompletedTasks().size() == 1);
    REQUIRE(list.getIncompleteTasks().size() == 1);
}

TEST_CASE("Multiple different tasks can be added") {
    TodoList list;
    
    bool result1 = list.add("Task 1");
    bool result2 = list.add("Task 2");
    bool result3 = list.add("Task 3");
    
    REQUIRE(result1 == true);
    REQUIRE(result2 == true);
    REQUIRE(result3 == true);
    REQUIRE(list.size() == 3);
}
