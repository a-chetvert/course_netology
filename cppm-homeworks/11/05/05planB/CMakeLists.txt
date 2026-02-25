cmake_minimum_required (VERSION 3.10)
project ("04")

set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)

# Библиотека
add_library(fig SHARED "Figure.h" "Figure.cpp")

# Устанавливаем определение для библиотеки
target_compile_definitions(fig PRIVATE fig_EXPORTS)


# Исполняемый файл
add_executable(04 "04.h" "04.cpp")

# Связываем библиотеку с приложением
target_link_libraries(04 PRIVATE fig)

# Чтобы 04 видел заголовок fig.h (если они в одной папке)
target_include_directories(04 PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})