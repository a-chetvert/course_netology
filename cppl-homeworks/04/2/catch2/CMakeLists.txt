# Создаём интерфейсную библиотеку для Catch2
add_library(Catch2 INTERFACE)

# Добавляем исходные файлы
target_sources(Catch2 INTERFACE
    ${CMAKE_CURRENT_SOURCE_DIR}/catch_amalgamated.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/catch_amalgamated.hpp
)

# Добавляем include директорию
target_include_directories(Catch2 INTERFACE
    ${CMAKE_CURRENT_SOURCE_DIR}
)
