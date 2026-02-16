# CMakeList.txt: проект CMake для 02; включите исходный код и определения,
# укажите здесь логику для конкретного проекта.
#
cmake_minimum_required (VERSION 3.10)

# Включение горячей перезагрузки для компиляторов MSVC, если поддерживается.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project ("02")

# Добавьте источник в исполняемый файл этого проекта.
add_executable(02 
    "02.cpp" 
    "Figure.cpp" 
    "Triangle.cpp" 
    "RightAngTriangle.cpp" 
    "IsoscelesTriangle.cpp" 
    "EquilateralTriangle.cpp" 
    "Quadrilateral.cpp" 
    "FRectangle.cpp" 
    "Square.cpp" 
    "Parallelogram.cpp" 
    "Rhomb.cpp"
)

target_sources(02 PRIVATE
    "Figure.h"
    "Triangle.h"
    "RightAngTriangle.h"
    "IsoscelesTriangle.h"
    "EquilateralTriangle.h"
    "Quadrilateral.h"
    "FRectangle.h"
    "Square.h"
    "Parallelogram.h"
    "Rhomb.h"
)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET 02 PROPERTY CXX_STANDARD 20)
endif()

# TODO: Добавьте тесты и целевые объекты, если это необходимо.
