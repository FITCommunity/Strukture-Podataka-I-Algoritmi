#include "pch.h"
#include "CppUnitTest.h"

#include "../ASP/LinkedStack.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace ASP_Test
{
	TEST_CLASS(LinkedStack_Test)
	{
	public:

		TEST_METHOD(AddOneItem_GetItemOnPop_Test)
		{
			LinkedStack<int> stack;
			stack.Push(1);

			Assert::AreEqual(stack.Pop(), 1);
		}

		TEST_METHOD(RemoveItemFromStack_GetLastAddedItem_Test)
		{
			LinkedStack<int> stack;
			stack.Push(1);
			stack.Push(2);
			stack.Push(3);
			stack.Push(4);
			stack.Push(5);

			Assert::AreEqual(stack.Pop(), 5);
		}

		TEST_METHOD(RequestTopOfStack_GetLastAddedItem_Test)
		{
			LinkedStack<int> stack;
			stack.Push(1);
			stack.Push(2);
			stack.Push(3);
			stack.Push(4);
			stack.Push(5);

			Assert::AreEqual(stack.Pop(), 5);
		}

		TEST_METHOD(RemoveAllItemsFromList_GetListIsEmpty_Test)
		{
			LinkedStack<int> stack;
			stack.Push(1);
			stack.Pop();


			Assert::IsTrue(stack.IsEmpty());
		}
	};
}
