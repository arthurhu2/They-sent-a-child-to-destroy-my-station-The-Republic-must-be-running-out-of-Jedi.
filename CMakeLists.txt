cmake_minimum_required(VERSION 3.25)
project(Lec20)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g")

set(SOURCE_FILES lower.cpp)
add_executable(Lower ${SOURCE_FILES})

set(SOURCE_FILES print_it.cpp)
add_executable(PrintIt ${SOURCE_FILES})

set(SOURCE_FILES count_sum.cpp)
add_executable(CountSum ${SOURCE_FILES})

set(SOURCE_FILES lambda_all_night.cpp)
add_executable(LambdaAllNight ${SOURCE_FILES})
