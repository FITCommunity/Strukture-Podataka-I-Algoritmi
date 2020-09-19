#include "pch.h"
#include "CppUnitTest.h"

#include "../ASP/ArrayList.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace ASP_Test
{
	TEST_CLASS(ArrayList_Test)
	{
	public:

		TEST_METHOD(AddOneItem_GetItemOnPosition0_Test)
		{
			ArrayList<int> list;
			list.Add(1);

			Assert::AreEqual(list.Get(0), 1);
		}

		TEST_METHOD(RemoveItemFromList_GetLastAddedItem_Test)
		{
			ArrayList<int> list;
			list.Add(1);
			list.Add(2);
			list.Add(3);
			list.Add(4);
			list.Add(5);

			Assert::AreEqual(list.Remove(), 5);
		}

		TEST_METHOD(RemoveAllItemsFromList_GetListIsEmpty_Test)
		{
			ArrayList<int> list;
			list.Add(1);
			list.Remove();


			Assert::IsTrue(list.IsEmpty());
		}

		TEST_METHOD(AddMaxItemsToList_GetListIsFull_Test)
		{
			ArrayList<int> list(5);
			list.Add(1);
			list.Add(2);
			list.Add(3);
			list.Add(4);
			list.Add(5);

			Assert::IsTrue(list.IsFull());
		}

		TEST_METHOD(Add5ItemsToList_GetListSize5_Test)
		{
			ArrayList<int> list;
			list.Add(1);
			list.Add(2);
			list.Add(3);
			list.Add(4);
			list.Add(5);

			Assert::AreEqual(list.Size(), 5);
		}
	};
}
