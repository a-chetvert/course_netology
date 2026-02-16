/**
 * @brief Задача 2. Остальные операции с дробями
 * @note  https://github.com/netology-code/cppm-homeworks/tree/main/09/02
 */
#include <iostream>
#include <string>
#include <numeric>

#define TYPE_NUM 0
#define TYPE_USER 1

// выбор способа ввода дробей
// TYPE_NUM - ввести 3/4 и 4/5 
// TYPE_USER - ручной ввод 
#define INPUT_TYPE TYPE_USER

class Fraction
{
private:
	int numerator_;
	int denominator_;

	/// @brief reduce сокращение дроби
	void reduce() {
		int common = std::gcd(numerator_, denominator_);
		numerator_ /= common;
		denominator_ /= common;
	}

public:
	Fraction(int numerator, int denominator)
	{
		numerator_ = numerator;
		denominator_ = denominator;
		reduce();
	}
	Fraction operator + (const Fraction& arg) const {
		int new_numerator = this->numerator_ * arg.denominator_ + arg.numerator_ * this->denominator_;
		int new_denominator = this->denominator_ * arg.denominator_;
		return Fraction(new_numerator, new_denominator);
	}
	Fraction operator - (const Fraction& arg) const {
		int new_numerator = this->numerator_ * arg.denominator_ - arg.numerator_ * this->denominator_;
		int new_denominator = this->denominator_ * arg.denominator_;
		return Fraction(new_numerator, new_denominator);
	}
	Fraction operator * (const Fraction& arg) const {
		int new_numerator = this->numerator_ * arg.numerator_;
		int new_denominator = this->denominator_ * arg.denominator_;
		return Fraction(new_numerator, new_denominator);
	}
	Fraction operator / (const Fraction& arg) const {
		int new_numerator = this->numerator_ * arg.denominator_ ;
		int new_denominator = this->denominator_ * arg.numerator_;
		return Fraction(new_numerator, new_denominator);
	}
	void operator ++ (){
		this->numerator_ += this->denominator_;
	}
	void operator -- (int) {
		this->numerator_ -= this->denominator_;
	}

	int get_num() const{
		return numerator_;
	}

	int get_denom() const {
		return denominator_;
	}

	std::string get_fraction() const {
		std::string tmp{""};
		tmp = std::to_string(get_num()) + "/" + std::to_string(get_denom());
		return tmp;
	}
};

int main()
{
#if INPUT_TYPE == TYPE_USER
	int tmpNumerator[2]{0,}, tmpDenominator[2]{0,};
	std::cout << "Введите числитель дроби 1: ";
	std::cin >> tmpNumerator[0];
	std::cout << "Введите знаменатель дроби 1: ";
	std::cin >> tmpDenominator[0];
	std::cout << "Введите числитель дроби 2: ";
	std::cin >> tmpNumerator[1];
	std::cout << "Введите знаменатель дроби 2: ";
	std::cin >> tmpDenominator[1];
#elif INPUT_TYPE == TYPE_NUM
	int tmpNumerator[2]{ 3, 4}, tmpDenominator[2]{ 4, 5};
#endif

	Fraction f1(tmpNumerator[0], tmpDenominator[0]);
	Fraction f2(tmpNumerator[1], tmpDenominator[1]);
	Fraction f1plusF2 = f1 + f2;
	Fraction f1minusF2 = f1 - f2;
	Fraction f1multiF2 = f1 * f2;
	Fraction f1divF2 = f1 / f2;

	std::cout << f1.get_fraction() << " + " << f2.get_fraction() << " = " << f1plusF2.get_fraction() << '\n';
	std::cout << f1.get_fraction() << " - " << f2.get_fraction() << " = " << f1minusF2.get_fraction() << '\n';
	std::cout << f1.get_fraction() << " * " << f2.get_fraction() << " = " << f1multiF2.get_fraction() << '\n';
	std::cout << f1.get_fraction() << " / " << f2.get_fraction() << " = " << f1divF2.get_fraction() << '\n';

	std::cout << "++" << f1.get_fraction() << " * " << f2.get_fraction() << " = ";
	++f1;
	Fraction ppF1multiF2 = f1 * f2;
	std::cout << ppF1multiF2.get_fraction() << '\n';
	std::cout << "Значение дроби 1 = " << f1.get_fraction() << '\n';

	std::cout <<f1.get_fraction() << "--" << " * " << f2.get_fraction() << " = ";
	Fraction F1mmMultiF2 = f1 * f2;
	std::cout << F1mmMultiF2.get_fraction() << '\n';
	f1--;
	std::cout << "Значение дроби 1 = " << f1.get_fraction() << '\n';
	return 0;
}