#include "pch.h"
#include "CppUnitTest.h"

#include <algorithm>

#include "../ASP/BucketSort.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace ASP_Test
{
	TEST_CLASS(BucketSort_Test)
	{
	public:

		TEST_METHOD(SortArrayDefault_GetSortedArrayInAscending_Test)
		{
			int niz[]{ 3, 6, 1, 5, 4, 2 };
			BucketSort(niz, 6);

			Assert::IsTrue(std::is_sorted(niz, niz + 6));
		}
	};
}
