#минимальная версия cmake
cmake_minimum_required(VERSION 3.10)
#имя проекта
project(demoCatch2)
#добавляем поддиректорию, в которой будет catch2
add_subdirectory(catch2)
#добавляем цель - приложение, у которого исходник с единственным приложением
add_executable(${PROJECT_NAME} main.cpp)

# Линкуемся с библиотекой Catch2 из поддиректории
target_link_libraries(${PROJECT_NAME} PRIVATE Catch2)