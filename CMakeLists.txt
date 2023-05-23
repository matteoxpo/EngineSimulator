cmake_minimum_required(VERSION 3.10)

project(main LANGUAGES CXX)


if (DEBUG)
# add_compile_options(-Wall -Werror -Wextra)
    add_compile_options(-g3 -ggdb -g)
endif()


set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_subdirectory(engine_lib)
include_directories(engine_lib)

add_subdirectory(engine_lib_tests)
include_directories(engine_lib_tests)

add_subdirectory(src)