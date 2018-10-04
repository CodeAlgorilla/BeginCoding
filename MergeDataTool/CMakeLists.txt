project(MergeDataTool)
cmake_minimum_required(VERSION 3.0)

set(Boost_USE_STATIC_LIBS OFF)
set(Boost_USE_MULTITHREADED ON)
set(Boost_USE_STATIC_RUNTIME OFF)
find_package(Boost 1.45.0 COMPONENTS filesystem regex)

INCLUDE_DIRECTORIES(include)
set (CMAKE_CXX_STANDARD 11)
set (CMAKE_CXX_STANDARD_REQUIRED TRUE)
set (CMAKE_CXX_EXTENSIONS FALSE)
set(CMAKE_C_FLAGS "-std=gnu++11 ${CMAKE_C_FLAGS}")
aux_source_directory(src SRC_LIST)

file(GLOB SRC_LIST "src/*.cpp"
                    "include/*.h")

if(Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS})
    add_executable(${PROJECT_NAME} ${SRC_LIST})
    target_link_libraries(${PROJECT_NAME} ${Boost_LIBRARIES})
endif()




