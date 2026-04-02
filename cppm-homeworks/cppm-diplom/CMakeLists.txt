cmake_minimum_required (VERSION 3.22)
project ("DiplomRace")

# Все файлы в одну папку
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

# Добавляем поддиректории
# lib/transport - динамическая библиотека
add_subdirectory(lib/transport)
# app - приложение, которое использует lib/transport
add_subdirectory(app)
