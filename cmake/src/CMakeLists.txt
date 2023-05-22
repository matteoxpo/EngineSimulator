cmake_minimum_required(VERSION 3.10)

project(SrcModule LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_executable(Executable.out 
    main.cpp
)



target_include_directories(
    Executable.out
    PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/../engine_lib
    ${CMAKE_CURRENT_SOURCE_DIR}/../engine_lib/interfaces
    ${CMAKE_CURRENT_SOURCE_DIR}/../engine_lib/entity
    ${CMAKE_CURRENT_SOURCE_DIR}/../engine_lib_tests/entity
    ${CMAKE_CURRENT_SOURCE_DIR}/../engine_lib_tests/interfaces
)

target_link_directories(
    Executable.out   
    PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/../engine_lib
    ${CMAKE_CURRENT_SOURCE_DIR}/../engine_lib_tests/interfaces
)

target_link_libraries(Executable.out 
    engines 
    engines_tests
)