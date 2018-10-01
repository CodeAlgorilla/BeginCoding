project(MergeDataTool)
cmake_minimum_required(VERSION 3.0)

INCLUDE_DIRECTORIES(include)
set (CMAKE_CXX_STANDARD 11)
set (CMAKE_CXX_STANDARD_REQUIRED TRUE)
set (CMAKE_CXX_EXTENSIONS FALSE)
set(CMAKE_C_FLAGS "-std=gnu++11 ${CMAKE_C_FLAGS}")
aux_source_directory(src SRC_LIST)

file(GLOB SRC_LIST "src/*.cpp"
                    "include/*.h")

add_executable(${PROJECT_NAME} ${SRC_LIST})

