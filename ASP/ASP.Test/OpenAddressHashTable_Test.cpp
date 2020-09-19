#include "pch.h"
#include "CppUnitTest.h"

#include "../ASP/OpenAddressHashTable.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace ASP_Test
{
	TEST_CLASS(OpenAddressHashTable_Test)
	{
	public:

		TEST_METHOD(RemoveExistingItem_GetTrue_Test)
		{
			OpenAddressHashTable<int> hashTable;
			hashTable.Add(1);

			Assert::IsTrue(hashTable.Remove(1));
		}

		TEST_METHOD(RemoveNonExistentItem_GetFalse_Test)
		{
			OpenAddressHashTable<int> hashTable;
			hashTable.Add(1);

			Assert::IsFalse(hashTable.Remove(2));
		}

		TEST_METHOD(AddZeroItems_GetTrueIsEmpty_Test)
		{
			OpenAddressHashTable<int> hashTable;

			Assert::IsTrue(hashTable.IsEmpty());
		}

		TEST_METHOD(AddMaxItems_GetTrueIsFull_Test)
		{
			OpenAddressHashTable<int> hashTable(5);
			hashTable.Add(1);
			hashTable.Add(2);
			hashTable.Add(3);
			hashTable.Add(4);
			hashTable.Add(5);

			Assert::IsTrue(hashTable.IsFull());
		}
	};
}
