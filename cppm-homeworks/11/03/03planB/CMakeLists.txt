cmake_minimum_required (VERSION 3.10)
project ("application")

set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)

# Библиотека
add_library(mydynlib SHARED "mydynlib.h" "mydynlib.cpp")

# Устанавливаем определение для библиотеки
target_compile_definitions(mydynlib PRIVATE MYDYNLIB_EXPORTS)


# Исполняемый файл
add_executable(application "application.h" "application.cpp")

# Связываем библиотеку с приложением
target_link_libraries(application PRIVATE mydynlib)

# Чтобы application видел заголовок mydynlib.h (если они в одной папке)
target_include_directories(application PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})