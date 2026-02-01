/**
 * @brief Задача 2. Фигуры. Стороны и углы
 * @note  https://github.com/netology-code/cppm-homeworks/tree/main/05/02
 */
#include <windows.h>
#include <iostream>

class Figure {
 protected:
  int a, b, c;  ///< стороны фигуры
  int A, B, C;  ///< углы

 public:
  Figure(int a, int b, int c, int A, int B, int C);
  virtual ~Figure() = default;
  int get_a();
  int get_b();
  int get_c();
  int get_A();
  int get_B();
  int get_C();
};

/**
 * @brief класс четырёхугольника
 */
class Quadrilateral : public Figure {
protected:
    int d;      ///< четвёртая сторона
    int D;      ///< четвёртый угол
public:
    Quadrilateral(int a, int b, int c, int d, int A, int B, int C, int D);
    int get_d();
    int get_D();
};

/**
 * @brief класс треугольника
 */
class Triangle : public Figure {
 public:
  Triangle(int a, int b, int c, int A, int B, int C) : Figure(a, b, c, A, B, C){};
};

/**
 * @brief класс прямоугольного треугольника
 */
class RightAngTriangle : public Triangle {
 public:
  RightAngTriangle(int a, int b, int c, int A, int B) : Triangle(a, b, c, A, B, 90){};
};

/**
 * @brief класс равнобедренного треугольника
 */
class IsoscelesTriangle : public Triangle {
public:
    IsoscelesTriangle(int a, int b, int A, int B) : Triangle(a, b, a, A, B, A) {};
};

/**
 * @brief класс равностороннего треугольника
 */
class EquilateralTriangle : public Triangle {
public:
    EquilateralTriangle(int a) : Triangle(a, a, a, 60, 60, 60) {};
};

/**
 * @brief класс прямоугольник
 */
class FRectangle : public Quadrilateral {
public:
    FRectangle(int a, int b) : Quadrilateral(a, b, a, b, 90, 90, 90, 90) {};
};

/**
 * @brief класс квадрата
 */
class Square : public Quadrilateral {
public:
    Square(int a) : Quadrilateral(a, a, a, a, 90, 90, 90, 90) {};
};

/**
 * @brief класс параллелограмм 
 */
class Parallelogram : public Quadrilateral {
public:
    Parallelogram(int a, int b, int A, int B) : Quadrilateral(a, b, a, b, A, B, A, B) {};
};

/**
 * @brief класс ромб 
 */
class Rhomb : public Quadrilateral {
public:
    Rhomb(int a, int A, int B) : Quadrilateral(a, a, a, a, A, B, A, B) {};
};

void print_info(Figure* lFigure) {
    std::cout << "Стороны: a=" << lFigure->get_a() 
              << " b=" << lFigure->get_b() 
              << " c=" << lFigure->get_c();
    
    // Проверяем, является ли фигура четырёхугольником
    if (Quadrilateral* quad = dynamic_cast<Quadrilateral*>(lFigure)) {
        std::cout << " d=" << quad->get_d();
    }
    
    std::cout << std::endl;
    
    std::cout << "Углы: A=" << lFigure->get_A() 
              << " B=" << lFigure->get_B() 
              << " C=" << lFigure->get_C();
    
    if (Quadrilateral* quad = dynamic_cast<Quadrilateral*>(lFigure)) {
        std::cout << " D=" << quad->get_D();
    }
    
    std::cout << "\n\n";
}

int main() {
  SetConsoleCP(1251);
  SetConsoleOutputCP(1251);

  Triangle newTriangle(10, 20, 30, 50, 60, 70);
  RightAngTriangle newRightAngledTriangle(10, 20, 30, 50, 60);
  IsoscelesTriangle newIsoscelesTriangle(10, 20, 50, 60);
  EquilateralTriangle newEquilateralTriangle(30);
  Quadrilateral newQuadrilateral(10, 20, 30, 40, 50, 60, 70, 80);
  FRectangle newFRectangle(10, 20);
  Square newSquare(20);
  Parallelogram newParallelogram(20, 30, 30, 40);
  Rhomb newRhomb(30, 30, 40);

  std::cout << "Треугольник: " << std::endl;
  print_info(&newTriangle);
  
  std::cout << "Прямоугольный треугольник:" << std::endl;
  print_info(&newRightAngledTriangle);
    
  std::cout << "Равнобедренный треугольник:" << std::endl;
  print_info(&newIsoscelesTriangle);
  
  std::cout << "Равносторонний треугольник:" << std::endl;
  print_info(&newEquilateralTriangle);

  std::cout << "Четырёхугольник:" << std::endl;
  print_info(&newQuadrilateral);

  std::cout << "Прямоугольник:" << std::endl;
  print_info(&newFRectangle);

  std::cout << "Квадрат:" << std::endl;
  print_info(&newSquare);

  std::cout << "Параллелограмм:" << std::endl;
  print_info(&newParallelogram);

  std::cout << "Ромб:" << std::endl;
  print_info(&newRhomb);

  return EXIT_SUCCESS;
}

Figure::Figure(int a, int b, int c, int A, int B, int C) {
  this->a = a;
  this->b = b;
  this->c = c;
  this->A = A;
  this->B = B;
  this->C = C;
}

Quadrilateral::Quadrilateral(int a, int b, int c, int d, int A, int B, int C, int D) : Figure(a, b, c, A, B, C) {
  this->d = d;
  this->D = D;
}

int Figure::get_a() {
  return a;
}
int Figure::get_b() {
  return b;
}
int Figure::get_c() {
  return c;
}
int Figure::get_A() {
  return A;
}
int Figure::get_B() {
  return B;
}
int Figure::get_C() {
  return C;
}

int Quadrilateral::get_d() {
    return d;
}

int Quadrilateral::get_D() {
    return D;
}