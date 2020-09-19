#include "pch.h"
#include "CppUnitTest.h"

#include "../ASP/ChainedHashTable.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace ASP_Test
{
	TEST_CLASS(ChainedHashTable_Test)
	{
	public:

		TEST_METHOD(RemoveExistingItem_GetTrue_Test)
		{
			ChainedHashTable<int> hashTable;
			hashTable.Add(1);

			Assert::IsTrue(hashTable.Remove(1));
		}

		TEST_METHOD(RemoveNonExistentItem_GetFalse_Test)
		{
			ChainedHashTable<int> hashTable;
			hashTable.Add(1);

			Assert::IsFalse(hashTable.Remove(2));
		}
	};
}
