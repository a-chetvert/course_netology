/**
 * @brief Задача 2. Исключения в конструкторах
 * @note  https://github.com/netology-code/cppm-homeworks/tree/main/08/02
 * 
 * @todo 
 * по ссылке
 * https://github.com/a-chetvert/course_netology/blob/go/cppm-homeworks/05/3/lesson_5_3.cpp
 * взять check() и добавить к каждому классу
 */
#include <windows.h>

#include <iostream>
#include <string>

 /// группа библиотек классов
#include "Figure.h"
#include "Triangle.h"
#include "RightAngTriangle.h"
#include "IsoscelesTriangle.h"
#include "EquilateralTriangle.h"
#include "Quadrilateral.h"
#include "FRectangle.h"
#include "Square.h"
#include "Parallelogram.h"
#include "Rhomb.h"

// обработка ошибок
#include "ExceptionFigure.h"

/**
  * @brief Функция для вывода информации о фигуре
  */
void print_info(Figure* figure) {
    figure->print_info();
}

int main() {
    // SetConsoleCP(1251);
    // SetConsoleOutputCP(1251);
    Figure* triangleFalse{ nullptr }, 
        *triangleTrue{ nullptr },
        *rightAngTriangleFalse{ nullptr },
        *rightAngTriangleTrue{ nullptr },
        *isoscelesTriangleFalse{ nullptr },
        *isoscelesTriangleTrue{ nullptr },
        *equilateralTriangleFalse{ nullptr },
        *equilateralTriangleTrue{ nullptr },
        *quadrilateralFalse{ nullptr },
        *quadrilateralTrue{ nullptr },
        * fRectangleFalse{ nullptr },
        * fRectangleTrue{ nullptr },
        * squareFalse{ nullptr },
        * squareTrue{ nullptr },
        * parallelogramFalse{ nullptr },
        * parallelogramTrue{ nullptr },
        * rhombFalse{ nullptr },
        * rhombTrue{ nullptr };

    try {
        triangleFalse = new Triangle(1, 20, 30, 50, 60, 60);
    }
    catch (const ExceptionFigure& err) {
        std::cout << "Ошибка создания фигуры. Причина: " << err.what() << std::endl;
    }

    try {
        triangleTrue = new Triangle(2, 30, 40, 60, 60, 60);
    }
    catch(const ExceptionFigure& err){
        std::cout << "Ошибка создания фигуры. Причина: " << err.what() << std::endl;
    }

    try {
        rightAngTriangleFalse = new RightAngTriangle(3, 60, 70, 60, 60, 60);
    }
    catch(const ExceptionFigure& err){
        std::cout << "Ошибка создания фигуры. Причина: " << err.what() << std::endl;
    }

    try {
        rightAngTriangleTrue = new RightAngTriangle(4, 20, 30, 40, 50, 90);
    }
    catch (const ExceptionFigure& err) {
        std::cout << "Ошибка создания фигуры. Причина: " << err.what() << std::endl;
    }

    try {
        isoscelesTriangleFalse = new IsoscelesTriangle(5, 20, 30, 40, 50, 90);
    }
    catch (const ExceptionFigure& err) {
        std::cout << "Ошибка создания фигуры. Причина: " << err.what() << std::endl;
    }

    try {
        isoscelesTriangleTrue = new IsoscelesTriangle(6, 20, 6, 90, 50, 90);
    }
    catch (const ExceptionFigure& err) {
        std::cout << "Ошибка создания фигуры. Причина: " << err.what() << std::endl;
    }

    try {
        equilateralTriangleFalse = new EquilateralTriangle(7, 7, 30, 40, 50, 90);
    }
    catch (const ExceptionFigure& err) {
        std::cout << "Ошибка создания фигуры. Причина: " << err.what() << std::endl;
    }

    try {
        equilateralTriangleTrue = new EquilateralTriangle(8, 8, 8, 90, 90, 90);
    }
    catch (const ExceptionFigure& err) {
        std::cout << "Ошибка создания фигуры. Причина: " << err.what() << std::endl;
    }

    try {
        quadrilateralFalse = new Quadrilateral(9, 9, 9, 30, 30, 40, 50, 90);
    }
    catch (const ExceptionFigure& err) {
        std::cout << "Ошибка создания фигуры. Причина: " << err.what() << std::endl;
    }

    try {
        quadrilateralTrue = new Quadrilateral(10, 10, 10, 10, 90, 90, 90, 90);
    }
    catch (const ExceptionFigure& err) {
        std::cout << "Ошибка создания фигуры. Причина: " << err.what() << std::endl;
    }

    try {
        fRectangleFalse = new FRectangle(11, 9, 11, 30, 30, 40, 50, 90);
    }
    catch (const ExceptionFigure& err) {
        std::cout << "Ошибка создания фигуры. Причина: " << err.what() << std::endl;
    }

    try {
        fRectangleTrue = new FRectangle(12, 10, 12, 10, 90, 90, 90, 90);
    }
    catch (const ExceptionFigure& err) {
        std::cout << "Ошибка создания фигуры. Причина: " << err.what() << std::endl;
    }

    try {
        squareFalse = new Square(13, 9, 11, 30, 30, 40, 50, 90);
    }
    catch (const ExceptionFigure& err) {
        std::cout << "Ошибка создания фигуры. Причина: " << err.what() << std::endl;
    }

    try {
        squareTrue = new Square(14, 14, 14, 14, 90, 90, 90, 90);
    }
    catch (const ExceptionFigure& err) {
        std::cout << "Ошибка создания фигуры. Причина: " << err.what() << std::endl;
    }

    try {
        parallelogramFalse = new Parallelogram(15, 9, 11, 30, 30, 40, 50, 90);
    }
    catch (const ExceptionFigure& err) {
        std::cout << "Ошибка создания фигуры. Причина: " << err.what() << std::endl;
    }

    try {
        parallelogramTrue = new Parallelogram(16, 14, 16, 14, 80, 100, 80, 100);
    }
    catch (const ExceptionFigure& err) {
        std::cout << "Ошибка создания фигуры. Причина: " << err.what() << std::endl;
    }

    try {
        rhombFalse = new Rhomb(17, 9, 11, 30, 30, 40, 50, 90);
    }
    catch (const ExceptionFigure& err) {
        std::cout << "Ошибка создания фигуры. Причина: " << err.what() << std::endl;
    }

    try {
        rhombTrue = new Rhomb(18, 18, 18, 18, 80, 100, 80, 100);
    }
    catch (const ExceptionFigure& err) {
        std::cout << "Ошибка создания фигуры. Причина: " << err.what() << std::endl;
    }


    /*
    std::cout << std::endl;


    if (triangleFalse != nullptr) {
        print_info(triangleTrue);
    }
    if (triangleTrue != nullptr) {
        print_info(triangleTrue);
    }
    if (rightAngTriangleFalse != nullptr) {
        print_info(rightAngTriangleFalse);
    }
    if (rightAngTriangleTrue != nullptr) {
        print_info(rightAngTriangleTrue);
    }

    */

        /*
        Parallelogram parallelogram(20, 30, 30, 40);
        Rhomb rhomb(30, 30, 40);
        */

    return EXIT_SUCCESS;
}
