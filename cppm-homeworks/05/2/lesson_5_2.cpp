/**
 * @brief Задача 2. Фигуры. Стороны и углы
 * @note  https://github.com/netology-code/cppm-homeworks/tree/main/05/02
 */
#include <windows.h>

#include <iostream>
#include <string>

#define METHOD_ 0               ///< print_info - метод класса
#define FUNCTION_ 1             ///< print_info() вызывает метод класса
#define STYLE_ANSWER METHOD_

class Figure {
 protected:
  std::string name;  ///< название фигуры

 public:
  Figure(std::string name) : name(name) {};
  std::string get_name() const;
  virtual void print_info() const = 0;
};

/**
 * @brief класс треугольника
 */
class Triangle : public Figure {
  const int a, b, c;  ///< стороны фигуры
  const int A, B, C;  ///< углы
 public:
  Triangle(int a, int b, int c, int A, int B, int C)
      : Figure("Треугольник"), a(a), b(b), c(c), A(A), B(B), C(C) {};
  void print_info() const override;
  int get_a() const;
  int get_b() const;
  int get_c() const;
  int get_A() const;
  int get_B() const;
  int get_C() const;
};

/**
 * @brief класс прямоугольного треугольника
 */
class RightAngTriangle : public Triangle {
 public:
  RightAngTriangle(int a, int b, int c, int A, int B);
};

/**
 * @brief класс равнобедренного треугольника
 */
class IsoscelesTriangle : public Triangle {
 public:
  IsoscelesTriangle(int a, int b, int A, int B);
};

/**
 * @brief класс равностороннего треугольника
 */
class EquilateralTriangle : public Triangle {
 public:
  EquilateralTriangle(int a);
};

/**
 * @brief класс четырёхугольника
 */
class Quadrilateral : public Figure {
  const int a, b, c, d;
  ;                      ///< стороны фигуры
  const int A, B, C, D;  ///< углы

 public:
  Quadrilateral(int a, int b, int c, int d, int A, int B, int C, int D)
      : Figure("Четырёхугольник"),
        a(a),
        b(b),
        c(c),
        d(d),
        A(A),
        B(B),
        C(C),
        D(D) {};
  void print_info() const override;
  int get_a() const;
  int get_b() const;
  int get_c() const;
  int get_d() const;
  int get_A() const;
  int get_B() const;
  int get_C() const;
  int get_D() const;
};

/**
* @brief класс прямоугольник
*/
class FRectangle : public Quadrilateral {
public:
 FRectangle(int a, int b);
};

/**
 * @brief класс квадрата
 */
 class Square : public Quadrilateral {
 public:
  Square(int a);
};

 /**
  * @brief класс параллелограмма
  */
 class Parallelogram : public Quadrilateral {
 public:
     Parallelogram(int a, int b, int A, int B);
 };

/**
 * @brief класс ромб
 */
 class Rhomb : public Quadrilateral {
 public:
  Rhomb(int a, int A, int B);
};


 /**
  * @brief Функция для вывода информации о фигуре
  */
void print_info(Figure* figure) {
     figure->print_info();
}

int main() {
  // SetConsoleCP(1251);
  // SetConsoleOutputCP(1251);

  Triangle triangle(10, 20, 30, 50, 60, 70);
  RightAngTriangle rightAngledTriangle(10, 20, 30, 50, 60);
  IsoscelesTriangle isoscelesTriangle(10, 20, 50, 60);
  EquilateralTriangle equilateralTriangle(30);
  Quadrilateral quadrilateral(10, 20, 30, 40, 50, 60, 70, 80);
  FRectangle fRectangle(10, 20);
  Square square(20);
  Parallelogram parallelogram(20, 30, 30, 40);
  Rhomb rhomb(30, 30, 40);
  
  #if (STYLE_ANSWER==METHOD_)
      print_info(&triangle);
      print_info(&rightAngledTriangle);
      print_info(&isoscelesTriangle);
      print_info(&equilateralTriangle);
      print_info(&quadrilateral);
      print_info(&fRectangle);
      print_info(&square);
      print_info(&parallelogram);
      print_info(&rhomb);
  #endif
  #if (STYLE_ANSWER==FUNCTION_)
      triangle.print_info();
      rightAngledTriangle.print_info();
      isoscelesTriangle.print_info();
      equilateralTriangle.print_info();

      quadrilateral.print_info();
      fRectangle.print_info();
      square.print_info();
      parallelogram.print_info();
      rhomb.print_info();
  #endif

  return EXIT_SUCCESS;
}

std::string Figure::get_name() const { return name; }

void Triangle::print_info() const {
  std::cout << get_name() << ": " << std::endl;
  std::cout << "Стороны: a=" << get_a() << " b=" << get_b() << " c=" << get_c()
            << std::endl;
  std::cout << "Углы: A=" << get_A() << " B=" << get_B() << " C=" << get_C()
            << "\n"
            << std::endl;
}

RightAngTriangle::RightAngTriangle(int a, int b, int c, int A, int B)
    : Triangle(a, b, c, A, B, 90) {
  name = "Прямоугольный треугольник";
}

IsoscelesTriangle::IsoscelesTriangle(int a, int b, int A, int B)
    : Triangle(a, b, a, A, B, A) {
  name = "Равнобедренный треугольник";
}

EquilateralTriangle::EquilateralTriangle(int a)
    : Triangle(a, a, a, 60, 60, 60) {
  name = "Равносторонний треугольник";
}

void Quadrilateral::print_info() const {
  std::cout << get_name() << ": " << std::endl;
  std::cout << "Стороны: a=" << get_a() << " b=" << get_b() << " c=" << get_c()
            << " d=" << get_d() << std::endl;
  std::cout << "Углы: A=" << get_A() << " B=" << get_B() << " C=" << get_C()
            << " D=" << get_D() << "\n"
            << std::endl;
}

FRectangle::FRectangle(int a, int b)
    : Quadrilateral(a, b, a, b, 90, 90, 90, 90) {
  name = "Прямоугольник";
}

Square::Square(int a)
    : Quadrilateral(a, a, a, a, 90, 90, 90, 90) {
    name = "Квадрат";
}

Parallelogram::Parallelogram(int a, int b, int A, int B)
    : Quadrilateral(a, b, a, b, A, B, A, B) {
    name = "Параллелограмм";
}

Rhomb::Rhomb(int a, int A, int B)
    : Quadrilateral(a, a, a, a, A, B, A, B) {
    name = "Ромб";
}

int Triangle::get_a() const { return a; }
int Triangle::get_b() const { return b; }
int Triangle::get_c() const { return c; }
int Triangle::get_A() const { return A; }
int Triangle::get_B() const { return B; }
int Triangle::get_C() const { return C; }

int Quadrilateral::get_a() const { return a; }
int Quadrilateral::get_b() const { return b; }
int Quadrilateral::get_c() const { return c; }
int Quadrilateral::get_d() const { return d; }
int Quadrilateral::get_A() const { return A; }
int Quadrilateral::get_B() const { return B; }
int Quadrilateral::get_C() const { return C; }
int Quadrilateral::get_D() const { return D; }
