cmake_minimum_required (VERSION 3.31)
project ("raceTransport")

# Включаем возможность создания динамической библиотеки
set(BUILD_SHARED_LIBS ON)

set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)

# Добавляем поддиректории
add_subdirectory(lib/transport)
add_subdirectory(app)
