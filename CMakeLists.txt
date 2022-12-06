cmake_minimum_required(VERSION 3.24)
project(game)

set(CMAKE_CXX_STANDARD 17)
add_executable(game main.cpp headers/snake.h main.c headers/conio.h headers/kbhit.h Datas/dataPack.h Datas/sampleCall.c)
find_package(PythonLibs REQUIRED)
include_directories(${PYTHON_INCLUDE_DIRS})
target_link_libraries(game ${PYTHON_LIBRARIES})