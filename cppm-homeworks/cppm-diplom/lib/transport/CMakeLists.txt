cmake_minimum_required (VERSION 3.22)
project ("transportLib")

set (SOURCES 
src/AirTransport.cpp
src/BootsAllTerrain.cpp
src/Broom.cpp
src/Camel.cpp
src/CamelFast.cpp
src/CarpetPlane.cpp
src/Centaur.cpp
src/Eagle.cpp
src/GndTransport.cpp
src/Race.cpp
src/Transport.cpp
) 

set (HEADERS 
inc/AirTransport.h
inc/BootsAllTerrain.h
inc/Broom.h
inc/Camel.h
inc/CamelFast.h
inc/CarpetPlane.h
inc/Centaur.h
inc/Eagle.h
inc/GndTransport.h
inc/LibApi.h
inc/Race.h
inc/RaceType.h
inc/Transport.h
) 

# Создаем DLL (SHARED library)
add_library(TRANSPORTRACE SHARED ${SOURCES} ${HEADERS})

target_compile_definitions(TRANSPORTRACE PRIVATE TRANSPORTRACE_EXPORTS)

target_include_directories(TRANSPORTRACE 
    PUBLIC 
        ${CMAKE_CURRENT_SOURCE_DIR}/inc
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/src
)
