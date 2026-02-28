/**
 * @brief Задача 3.
 * @note  https://netology.ru/profile/program/cppm-41/lessons/575464/lesson_items/3106499
 * Дополните класс ExtArray методом checkSum, возвращающим контрольную сумму для битового массива
 (содержащего только нули и единицы).
· Метод должен работать только с массивами типа bool и int.
Если тип элементов массива отличается от данных двух, то выбрасывается исключение std::bad_typeid.
· Метод должен проверять содержание целочисленного массива. Если в массиве присутствуют значения,
отличные от 0 и 1, то выбрасывается исключение std::logic_error.
· Для целочисленных и булевских массивов метод возвращает количество элементов, установленных в значение 1(true).

Напишите тестовые кейсы на проверку типа массива, проверку содержимого массива и на проверку правильности результата.
 */

#include "pch.h"
#include "CppUnitTest.h"
#include "../extended_array.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace tests
{
	TEST_CLASS(ExcdedArrayTest)
	{
	public:
		// проверка на тип массива
		TEST_METHOD(checkSumInvalidType)
		{
			ExtArray<double> v0{ 1.0, 1.0, 0.0, 1.0 };

			Assert::ExpectException<std::bad_typeid>(
				[&] {
					v0.checkSum();
				}
			);
		}
		// проверка на содержание массива
		TEST_METHOD(checkSumFalseContent)
		{
			ExtArray<int> v1{ 0, 1, 1, 2 };

			Assert::ExpectException<std::logic_error>(
				[&] {
					v1.checkSum();
				}
			);
		}

		// проверка правильности подсчета элементов в значении true
		TEST_METHOD(checkSumCountNumTrue)
		{
			ExtArray<bool> v1{ false, true, true, true };
			Assert::AreEqual<int>(v1.checkSum(), 3);
		}

		// проверка правильности подсчета элементов в значении 1
		TEST_METHOD(checkSumCountNum1)
		{
			ExtArray<int> v1{ 0, 1, 1, 0 };

			Assert::AreEqual<int>(v1.checkSum(), 2);
		}
		TEST_METHOD(MeanAverage)
		{
			ExtArray<int> v0{2, 4, 6, 8};
			Assert::AreEqual<int>(4, v0.mean(0, 2));
		}
		//  значения для номеров указаны неверно (начальный номер больше или равен конечному)
		TEST_METHOD(MeanAverageSwapArgsOrOth)
		{
			ExtArray<int> v1{ 2, 4, 6, 8 };
			Assert::ExpectException<std::invalid_argument>(
				[&] {
					v1.mean(2, 0);
				}
			);
		}
		//  начальный номер равен конечному
		TEST_METHOD(MeanAverageEqualArgs)
		{
			ExtArray<int> v2{ 2, 4, 6, 8 };
			
			try {
				v2.mean(1, 1);
				Assert::Fail(L"Expected exception");
			}
			catch (const std::invalid_argument& e) {
				Assert::AreEqual("numFirst == numSecond", e.what());
			}
		}
		//  начальный номер больше конечного
		TEST_METHOD(MeanAverageSwapArgs)
		{
			ExtArray<int> v2{ 2, 4, 6, 8 };
			
			try {
				v2.mean(2, 0);
				Assert::Fail(L"Expected exception");
			}
			catch (const std::invalid_argument& e) {
				Assert::AreEqual("numFirst > numSecond", e.what());
			}
		}

		TEST_METHOD(Mean)
		{
			ExtArray<int> v1{};
			Assert::AreEqual<int>(0, v1.mean());
		}
		TEST_METHOD(Median) {
			ExtArray<double> v2{};
			Assert::AreEqual(v2.median(), 0.0);
		}
		TEST_METHOD(Mode) {
			ExtArray<int> v3{};
			Assert::AreEqual(v3.mode().second, 0);
		}
	};
}
