/**
 * @brief Задача 3. Фигуры. Методы
 * @note  https://github.com/netology-code/cppm-homeworks/tree/main/05/03
 */
#include <windows.h>
#include <iostream>
#include <string>

class Figure {
protected:
    int sides_count;    ///< количество сторон
    std::string name;   ///< название фигуры

public:
    Figure() : sides_count(0), name("Фигура") {}

    virtual void print_info();
    virtual bool check();
};

/**************************************************/
// классы треугольников
/**************************************************/
class Triangle : public Figure {
protected:
    int a, b, c;    // Стороны
    int A, B, C;    // Углы (в градусах)
    
public:
    Triangle(int side_a, int side_b, int side_c, 
             int angle_a, int angle_b, int angle_c) 
        : a(side_a), b(side_b), c(side_c), 
          A(angle_a), B(angle_b), C(angle_c) {
        sides_count = 3;
        name = "Треугольник";
    }
    
    void print_info() override;
    bool check() override;
};

class RightTriangle : public Triangle {
public:
    RightTriangle(int side_a, int side_b, int side_c, 
             int angle_a, int angle_b) 
        : Triangle (side_a, side_b, side_c, 
          angle_a, angle_b, 90) {
        name = "Прямоугольный треугольник";
    }
    
    bool check() override;
};

class IsoscelesTriangle : public Triangle {
public:
    IsoscelesTriangle(int side_a, int side_b, int angle_a, int angle_b)
        : Triangle(side_a, side_b, side_a, angle_a, angle_b, angle_a) {
        name = "Равнобедренный треугольник";
    }

    bool check() override;
};

class EquilateralTriangle : public IsoscelesTriangle{
public:
    EquilateralTriangle(int side)
        : IsoscelesTriangle(side, side, 60, 60) {
        name = "Равносторонний треугольник";
    }

    bool check() override;
};

/**************************************************/
// классы четырехугольников
/**************************************************/
class Quadrilateral : public Figure {
protected:
    int a, b, c, d;    // Стороны
    int A, B, C, D;    // Углы (в градусах)

public:
    Quadrilateral(int side_a, int side_b, int side_c, int side_d,
        int angle_a, int angle_b, int angle_c, int angle_d)
        : a(side_a), b(side_b), c(side_c), d(side_d),
        A(angle_a), B(angle_b), C(angle_c), D(angle_d) {
        sides_count = 4;
        name = "Четырёхугольник";
    }

    void print_info() override;
    bool check() override;
};



int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Figure figure;
    Triangle triangle(10, 20, 30, 50, 60, 70);
    RightTriangle falseRightTriangle(10, 20, 30, 50, 60);
    RightTriangle trueRightTriangle(10, 20, 30, 50, 40);
    IsoscelesTriangle falseIsoscelesTriangle(10, 20, 50, 60);
    IsoscelesTriangle trueIsoscelesTriangle(30, 20, 50, 80);
    EquilateralTriangle equilateralTriangle(30);
    Quadrilateral falseQuadrilateral(10, 20, 30, 40, 50, 60, 70, 80);
    Quadrilateral trueQuadrilateral(10, 20, 30, 40, 60, 90, 100, 110);

    figure.print_info();
    std::cout << "\n";
    triangle.print_info();
    std::cout << "\n";
    falseRightTriangle.print_info();
    std::cout << "\n";
    trueRightTriangle.print_info();
    std::cout << "\n";
    falseIsoscelesTriangle.print_info();
    std::cout << "\n";
    trueIsoscelesTriangle.print_info();
    std::cout << "\n";
    equilateralTriangle.print_info();
    std::cout << "\n";
    falseQuadrilateral.print_info();
    std::cout << "\n";
    trueQuadrilateral.print_info();
    std::cout << "\n";


    //Quadrilateral newQuadrilateral(10, 20, 30, 40, 50, 60, 70, 80);
    //FRectangle newFRectangle(10, 20);
    //Square newSquare(20);
    //Parallelogram newParallelogram(20, 30, 30, 40);
    //Rhomb newRhomb(30, 30, 40);

    //std::cout << "Треугольник: " << std::endl;
    //print_info(&newTriangle);


    return EXIT_SUCCESS;
}


/**
 * @brief Виртуальный метод для вывода информации
 * 
 */
void Figure::print_info(){
    std::cout << name << ":" << std::endl;
    std::cout << (check() ? "Правильная" : "Неправильная") << std::endl;
    std::cout << "Количество сторон: " << sides_count << std::endl;
}

/**
 * @brief Виртуальный метод для проверки правильности
 * 
 * @return true правильно
 * @return false неправильно
 */
bool Figure::check(){
    return (sides_count == 0);
}

/**
 * @brief переопределение виртуального метода для вывода информации
 * 
 */
void Triangle::print_info(){
    Figure::print_info(); // Вызов базовой версии
    std::cout << "Стороны: a=" << a << " b=" << b << " c=" << c << std::endl;
    std::cout << "Углы: A=" << A << " B=" << B << " C=" << C << std::endl;
}

/**
 * @brief Переопределение виртального метода для проверки правильности
 * 
 * @return true правильно
 * @return false неправильно
 */
bool Triangle::check(){
    // Проверяем, что все углы и стороны больше нуля
    if((A>0) && (B>0) && (C>0) && (a>0) && (b>0 )&& c>0)
        // Проверяем сумму углов треугольника
        return ((A + B + C) == 180);
    else false;
}

/**
 * @brief Переопределение виртального метода для проверки правильности
 * 
 * @return true правильно
 * @return false неправильно
 */
bool RightTriangle::check(){
    // Проверяем, правильный ли треугольник
    // и является С угол прямым
    return (C == 90) && Triangle::check();
}

/**
 * @brief Переопределение виртального метода для проверки правильности
 *
 * @return true правильно
 * @return false неправильно
 */
bool IsoscelesTriangle::check() {
    // Проверяем условия равнобедренного треугольника
    return (a == c) && (A == C) && Triangle::check();
}


/**
 * @brief Переопределение виртального метода для проверки правильности
 *
 * @return true правильно
 * @return false неправильно
 */
bool EquilateralTriangle::check() {
    // Проверяем условия равнобедренного треугольника
    return (a == b) && (A == B) && (B == 60) && Triangle::check();
}

void Quadrilateral::print_info() {
    Figure::print_info();
    std::cout << "Стороны: a=" << a << " b=" << b
        << " c=" << c << " d=" << d << std::endl;
    std::cout << "Углы: A=" << A << " B=" << B
        << " C=" << C << " D=" << D << std::endl;
}

bool Quadrilateral::check() {
    return ((A + B + C + D) == 360);
}

/**
 * @brief класс четырёхугольника
 */
//class Quadrilateral : public Figure {
//protected:
//    int a, b, c;        ///< стороны фигуры
//    int A, B, C;        ///< углы
//    int d;      ///< четвёртая сторона
//    int D;      ///< четвёртый угол
//public:
//    Quadrilateral(int a, int b, int c, int d, int A, int B, int C, int D);
//    int get_d();
//    int get_D();
//};
//
///**
// * @brief класс треугольника
// */
//class Triangle : public Figure {
//public:
//    Triangle(int a, int b, int c, int A, int B, int C) : Figure(a, b, c, A, B, C) {};
//};
//
///**
// * @brief класс прямоугольного треугольника
// */
//class RightAngTriangle : public Triangle {
//public:
//    RightAngTriangle(int a, int b, int c, int A, int B) : Triangle(a, b, c, A, B, 90) {};
//};
//
///**
// * @brief класс равнобедренного треугольника
// */
//class IsoscelesTriangle : public Triangle {
//public:
//    IsoscelesTriangle(int a, int b, int A, int B) : Triangle(a, b, a, A, B, A) {};
//};
//
///**
// * @brief класс равностороннего треугольника
// */
//class EquilateralTriangle : public Triangle {
//public:
//    EquilateralTriangle(int a) : Triangle(a, a, a, 60, 60, 60) {};
//};
//
///**
// * @brief класс прямоугольник
// */
//class FRectangle : public Quadrilateral {
//public:
//    FRectangle(int a, int b) : Quadrilateral(a, b, a, b, 90, 90, 90, 90) {};
//};
//
///**
// * @brief класс квадрата
// */
//class Square : public Quadrilateral {
//public:
//    Square(int a) : Quadrilateral(a, a, a, a, 90, 90, 90, 90) {};
//};
//
///**
// * @brief класс параллелограмм
// */
//class Parallelogram : public Quadrilateral {
//public:
//    Parallelogram(int a, int b, int A, int B) : Quadrilateral(a, b, a, b, A, B, A, B) {};
//};
//
///**
// * @brief класс ромб
// */
//class Rhomb : public Quadrilateral {
//public:
//    Rhomb(int a, int A, int B) : Quadrilateral(a, a, a, a, A, B, A, B) {};
//};
//
//void print_info(Figure* lFigure) {
//    std::cout << "Стороны: a=" << lFigure->get_a()
//        << " b=" << lFigure->get_b()
//        << " c=" << lFigure->get_c();
//
//    // Проверяем, является ли фигура четырёхугольником
//    if (Quadrilateral* quad = dynamic_cast<Quadrilateral*>(lFigure)) {
//        std::cout << " d=" << quad->get_d();
//    }
//
//    std::cout << std::endl;
//
//    std::cout << "Углы: A=" << lFigure->get_A()
//        << " B=" << lFigure->get_B()
//        << " C=" << lFigure->get_C();
//
//    if (Quadrilateral* quad = dynamic_cast<Quadrilateral*>(lFigure)) {
//        std::cout << " D=" << quad->get_D();
//    }
//
//    std::cout << "\n\n";
//}
