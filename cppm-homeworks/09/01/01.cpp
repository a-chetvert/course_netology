/**
 * @brief Задача 1. Сравнения в дробях
 * @note  https://github.com/netology-code/cppm-homeworks/tree/main/09/01
 */
 #include <iostream>

class Fraction
{
private:
	int numerator_;
	int denominator_;

public:
	Fraction(int numerator, int denominator)
	{
		numerator_ = numerator;
		denominator_ = denominator;
	}
	bool operator == (const Fraction& arg) const {
		return (this->numerator_ * arg.denominator_ == arg.numerator_ * this->denominator_);
	}
	bool operator != (const Fraction& arg) const {
		return !(*this == arg);
	}
	bool operator < (const Fraction& arg) const {
		return (this->numerator_ * arg.denominator_ < arg.numerator_ * this->denominator_);
	}
	bool operator > (const Fraction& arg) const {
		return arg < *this;
	}
	bool operator <= (const Fraction& arg) const {
		return (*this < arg || *this == arg);
	}
	bool operator >= (const Fraction& arg) const {
		return (*this > arg || *this == arg);
	}
};

int main()
{
	Fraction f1(4, 3);
	Fraction f2(6, 11);

	std::cout << "f1" << ((f1 == f2) ? " == " : " not == ") << "f2" << '\n';
	std::cout << "f1" << ((f1 != f2) ? " != " : " not != ") << "f2" << '\n';
	std::cout << "f1" << ((f1 < f2) ? " < " : " not < ") << "f2" << '\n';
	std::cout << "f1" << ((f1 > f2) ? " > " : " not > ") << "f2" << '\n';
	std::cout << "f1" << ((f1 <= f2) ? " <= " : " not <= ") << "f2" << '\n';
	std::cout << "f1" << ((f1 >= f2) ? " >= " : " not >= ") << "f2" << '\n';
	return 0;
}