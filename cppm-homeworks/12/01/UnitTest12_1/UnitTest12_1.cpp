#include "pch.h"
#include "CppUnitTest.h"
#include "../01/extended_array.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest121
{
	TEST_CLASS(ExcdedArrayTest)
	{
	public:
		
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
			Assert::AreEqual(v3.mode().first, 0);
		}
	};
}
