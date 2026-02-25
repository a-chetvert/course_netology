cmake_minimum_required (VERSION 3.10)

project ("CmakeLib")

# Создаем импортированную библиотеку
add_library(mydynlib SHARED IMPORTED)

# Указываем пути к .lib и .dll файлам
set_target_properties(mydynlib PROPERTIES
    IMPORTED_LOCATION "${CMAKE_CURRENT_SOURCE_DIR}/x64/Debug/mydynlib.dll"
    IMPORTED_IMPLIB "${CMAKE_CURRENT_SOURCE_DIR}/x64/Debug/mydynlib.lib"
)

set(LIB_PATH "${CMAKE_CURRENT_SOURCE_DIR}/x64/Debug")
set(LIB_NAME "mydynlib") 

target_include_directories(mydynlib INTERFACE 
    ${CMAKE_CURRENT_SOURCE_DIR}
)

add_executable(CmakeLib application.cpp application.h)

link_directories(${LIB_PATH})

target_link_libraries(${PROJECT_NAME} PRIVATE ${LIB_NAME})
#add_subdirectory(application)

#target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/second)

#target_link_libraries(${PROJECT_NAME} PRIVATE second)