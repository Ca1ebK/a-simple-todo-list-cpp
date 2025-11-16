cmake_minimum_required(VERSION 3.24)

project(a_simple_todo_list)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

Include(FetchContent)

FetchContent_Declare(
  Catch2
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG        v3.8.1
)

FetchContent_MakeAvailable(Catch2)

add_executable(todo_test tests/todo_test.cpp src/Task.cpp src/TodoList.cpp)
add_executable(main main.cpp src/Task.cpp src/TodoList.cpp)

target_link_libraries(todo_test PRIVATE Catch2::Catch2WithMain)
