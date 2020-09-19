#include "pch.h"
#include "CppUnitTest.h"

#include <algorithm>

#include "../ASP/QuickSort.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace ASP_Test
{
	TEST_CLASS(QuickSort_Test)
	{
	public:

		TEST_METHOD(SortArrayDefault_GetSortedArrayInAscending_Test)
		{
			int niz[]{ 3, 6, 1, 5, 4, 2 };
			QuickSort(niz, 6);

			Assert::IsTrue(std::is_sorted(niz, niz + 6));
		}

		TEST_METHOD(SortArrayPassComparisonFunctionThatReturnsTrueForGreaterThen_GetSortedArrayInDesc_Test)
		{
			int niz[]{ 3, 6, 1, 5, 4, 2 };
			QuickSort(niz, 6, [](int x, int y) {return x < y; });

			Assert::IsTrue(std::is_sorted(niz, niz + 6, std::greater<>()));
		}

	};
}
