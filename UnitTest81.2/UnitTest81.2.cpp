#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_08.1.char/Lab_08.1.char.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest812
{
	TEST_CLASS(UnitTest812)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Assert::AreEqual(4, Count("nono on"));
			Assert::AreEqual(0, Count("abc"));
			Assert::AreEqual(3, Count("nono"));
			Assert::AreEqual(0, Count(""));
			Assert::AreEqual(0, Count(nullptr));
		}
		TEST_METHOD(TestMethod2)
		{
			char input1[10] = "no";
			char* result1 = Replace(input1);
			Assert::AreEqual("***", input1);
			Assert::AreEqual("***", result1);
			delete[] result1;

			char input2[15] = "onion";
			char* result2 = Replace(input2);
			Assert::AreEqual("***i***", input2);
			Assert::AreEqual("***i***", result2);
			delete[] result2;

			char input3[10] = "xyz";
			char* result3 = Replace(input3);
			Assert::AreEqual("xyz", input3);
			Assert::AreEqual("xyz", result3);
			delete[] result3;

			char input4[20] = "nono on";
			char* result4 = Replace(input4);
			Assert::AreEqual("****** ***", input4);
			Assert::AreEqual("****** ***", result4);
			delete[] result4;
		}
	};
}
