cmake_minimum_required (VERSION 3.22)
project (app)

set (SOURCES 
   main.cpp
   ConsoleUI.cpp
)

set (HEADERS 
  ConsoleUI.h
)

add_executable(app ${SOURCES} ${HEADERS})

# подключаем библиотеку
target_link_libraries(app PRIVATE TRANSPORTRACE)