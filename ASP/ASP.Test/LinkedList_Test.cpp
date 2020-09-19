#include "pch.h"
#include "CppUnitTest.h"

#include "../ASP/LinkedList.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace ASP_Test
{
	TEST_CLASS(LinkedList_Test)
	{
	public:

		TEST_METHOD(AddOneItem_GetItemOnPosition0_Test)
		{
			LinkedList<int> list;
			list.Add(1);
			
			Assert::AreEqual(list.Get(0), 1);
		}
		TEST_METHOD(RemoveItemFromStack_GetLastAddedItem_Test)
		{
			LinkedList<int> list;
			list.Add(1);
			list.Add(2);
			list.Add(3);
			list.Add(4);
			list.Add(5);

			Assert::AreEqual(list.Remove(), 5);
		}

		TEST_METHOD(RemoveAllItemsFromList_GetListIsEmpty_Test)
		{
			LinkedList<int> list;
			list.Add(1);
			list.Remove();


			Assert::IsTrue(list.IsEmpty());
		}
	};
}
