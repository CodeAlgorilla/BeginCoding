project(MergeDataTool)
cmake_minimum_required(VERSION 2.8)

INCLUDE_DIRECTORIES(include)

aux_source_directory(src SRC_LIST)

file(GLOB SRC_LIST "src/*.cpp"
                    "include/*.h")

add_executable(${PROJECT_NAME} ${SRC_LIST})

