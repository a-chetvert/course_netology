cmake_minimum_required (VERSION 3.22)
project ("transportLib")

# TODO разобраться с этим!
set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)

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
add_library(transportLib SHARED ${HEADERS} ${SOURCES})

# TODO разобраться почему PUBLIC
target_include_directories(transportLib PUBLIC inc)