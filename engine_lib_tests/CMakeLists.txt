cmake_minimum_required(VERSION 3.10)

project(engine_lib_tests LANGUAGES CXX)


add_library(engines_tests STATIC 
    entity/EngineTestStand.cpp
    entity/EngineTestStand.hpp

    entity/serializer/InternalCombucstionEngineDataSerializer.cpp
    entity/serializer/InternalCombucstionEngineDataSerializer.hpp

    interfaces/AEngineDataSerializer.hpp
    interfaces/ATestStand.hpp
)

target_include_directories(
    engines_tests
    PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/../engine_lib
    ${CMAKE_CURRENT_SOURCE_DIR}/../engine_lib/interfaces
    ${CMAKE_CURRENT_SOURCE_DIR}/../engine_lib/entity

)

target_link_directories(
    engines_tests   
    PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/../engine_lib
)


target_link_libraries(engines_tests engines)