#include "pch.h"
#include "CppUnitTest.h"

#include <algorithm>

#include "../ASP/RadixSort.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace ASP_Test
{
	TEST_CLASS(RadixSort_Test)
	{
	public:

		TEST_METHOD(SortArrayDefault_GetSortedArrayInAscending_Test)
		{
			int niz[]{ 3, 6, 1, 5, 4, 2 };
			RadixSort(niz, 6);

			Assert::IsTrue(std::is_sorted(niz, niz + 6));
		}
	};
}
