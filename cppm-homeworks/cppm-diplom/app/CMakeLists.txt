cmake_minimum_required (VERSION 3.10)
project ("raceTransport")

set (SOURCES 
   main.cpp
   ConsoleUI.cpp
)

set (HEADERS 
  ConsoleUI.h
)

set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)

add_executable(main ${SOURCES} ${HEADERS})
