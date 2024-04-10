#include "pch.h"
#include "CppUnitTest.h"

#include <stdio.h>
#include <stdlib.h>

int a(int n, int* str) {
	int sum, max;
	sum = max = 0;
	for (int i = 0; i < n; i++) {
		if (sum < 0) {
			sum = str[i];
		}
		else {
			sum += str[i];
		}
		if (sum > max) {
			max = sum;
		}
	}
	if (max < 0) max = 0;
	return max;
}

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			int n=5;
			int str[5] = {1,2,3,4,5};
			Assert::AreEqual(15, a(n, str));
		}

		TEST_METHOD(TestMethod2)
		{
			int n = 5;
			int str[5] = { -1,-2,-3,-4,-5 };
			Assert::AreEqual(0, a(n, str));
		}
	};
}
