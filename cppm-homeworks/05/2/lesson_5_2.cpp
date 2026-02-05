/**
 * @brief Задача 2. Фигуры. Стороны и углы
 * @note  https://github.com/netology-code/cppm-homeworks/tree/main/05/02
 */
#include <windows.h>
#include <iostream>
#include <string>

class Figure {
 protected:
  int a, b, c;        ///< стороны фигуры
  int A, B, C;        ///< углы
  std::string name;   ///< название фигуры

 public:
  Figure(int a, int b, int c, int A, int B, int C);
  std::string get_name() const;
  virtual void print_info() const = 0;
  int get_a() const;
  int get_b() const;
  int get_c() const;
  int get_A() const;
  int get_B() const;
  int get_C() const;
};


/**
 * @brief класс треугольника
 */
class Triangle : public Figure {
 public:
     Triangle(int a, int b, int c, int A, int B, int C);
     void print_info() const override;
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
 * @brief класс четырёхугольника
 */
class Quadrilateral : public Figure {
protected:
    int d;      ///< четвёртая сторона
    int D;      ///< четвёртый угол
public:
    Quadrilateral(int a, int b, int c, int d, int A, int B, int C, int D);
    int get_d() const;
    int get_D() const;
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

int main() {
  SetConsoleCP(1251);
  SetConsoleOutputCP(1251);

  Triangle newTriangle(10, 20, 30, 50, 60, 70);
  //RightAngTriangle newRightAngledTriangle(10, 20, 30, 50, 60);
  //IsoscelesTriangle newIsoscelesTriangle(10, 20, 50, 60);
  //EquilateralTriangle newEquilateralTriangle(30);
  //Quadrilateral newQuadrilateral(10, 20, 30, 40, 50, 60, 70, 80);
  //FRectangle newFRectangle(10, 20);
  //Square newSquare(20);
  //Parallelogram newParallelogram(20, 30, 30, 40);
  //Rhomb newRhomb(30, 30, 40);

  
  /*
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
  */

  return EXIT_SUCCESS;
}

Figure::Figure(int a, int b, int c, int A, int B, int C) {
  this->a = a;
  this->b = b;
  this->c = c;
  this->A = A;
  this->B = B;
  this->C = C;
  name = "Фигура";
}

std::string Figure::get_name() const{
    return name;
}

Triangle::Triangle(int a, int b, int c, int A, int B, int C) : Figure(a, b, c, A, B, C) {
    name = "Треугольник";
}

void Triangle::print_info() const {
    std::cout << get_name() << ": " << std::endl;
    std::cout << "Стороны: a=" << get_a()
        << " b=" << get_b()
        << " c=" << get_c();
}


Quadrilateral::Quadrilateral(int a, int b, int c, int d, int A, int B, int C, int D) : Figure(a, b, c, A, B, C) {
  this->d = d;
  this->D = D;
  this->name = "Четырехугольник";
}

int Figure::get_a() const {
  return a;
}
int Figure::get_b() const {
  return b;
}
int Figure::get_c() const {
  return c;
}
int Figure::get_A() const {
  return A;
}
int Figure::get_B() const {
  return B;
}
int Figure::get_C() const {
  return C;
}

int Quadrilateral::get_d() const {
    return d;
}

int Quadrilateral::get_D() const {
    return D;
}