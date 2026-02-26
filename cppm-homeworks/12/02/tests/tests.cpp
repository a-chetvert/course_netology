#include "pch.h"
#include "CppUnitTest.h"
#include "../extended_array.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace tests
{
	TEST_CLASS(ExcdedArrayTest)
	{
	public:
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
