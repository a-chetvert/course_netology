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
			ExtArray<int> v1{};
			Assert::AreEqual<int>(v1.mean(), 0);
		}

		TEST_METHOD(Mean)
		{
			ExtArray<int> v1{};
			Assert::AreEqual<int>(v1.mean(), 0);
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
