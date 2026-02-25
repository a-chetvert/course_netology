cmake_minimum_required (VERSION 3.10)

project ("03")

add_subdirectory(application)

target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/second)

target_link_libraries(${PROJECT_NAME} PRIVATE second)