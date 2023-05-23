cmake_minimum_required(VERSION 3.10)

project(engine_lib LANGUAGES CXX)


add_library(engines STATIC 
    entity/EngineType.hpp 
    
    entity/InternalCombucstionEngine.hpp
    entity/InternalCombucstionEngine.cpp
    
    entity/InternalCombucstionEngineData.hpp
    entity/InternalCombucstionEngineData.cpp

    interfaces/AEngine.hpp
    interfaces/AEngineData.hpp
)