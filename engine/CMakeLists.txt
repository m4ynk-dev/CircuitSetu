cmake_minimum_required(VERSION 3.10)
project(CircuitSetuEngine CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories(include)

set(SOURCE_FILES
    src/components.cpp
    src/solver.cpp
    src/wasm_bindings.cpp
)

add_executable(circuit_engine ${SOURCE_FILES})

if (EMSCRIPTEN)
    set_target_properties(circuit_engine PROPERTIES LINK_FLAGS 
        "-lembind -s WASM=1 -s MODULARIZE=1 -s EXPORT_NAME='createCircuitEngine' -O3"
    )
    
    set_target_properties(circuit_engine PROPERTIES SUFFIX ".js")
endif()
