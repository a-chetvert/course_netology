cmake_minimum_required (VERSION 3.10)

project ("03")

add_subdirectory(second)

set (SOURCES 
   03.cpp
)

set (HEADERS 
  03.h
)

add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})
#set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/second)

target_link_libraries(${PROJECT_NAME} PRIVATE second)