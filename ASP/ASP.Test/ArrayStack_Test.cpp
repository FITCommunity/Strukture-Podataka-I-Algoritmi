#include "pch.h"
#include "CppUnitTest.h"

#include "../ASP/ArrayStack.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace ASP_Test
{
	TEST_CLASS(ArrayStack_Test)
	{
	public:


		TEST_METHOD(RemoveItemFromStack_GetLastAddedItem_Test)
		{
			ArrayStack<int> stack;
			stack.Push(1);
			stack.Push(2);
			stack.Push(3);
			stack.Push(4);
			stack.Push(5);

			Assert::AreEqual(stack.Pop(), 5);
		}

		TEST_METHOD(AddItems_GetLastItemAddedOnTop_Test)
		{
			ArrayStack<int> stack;
			stack.Push(1);
			stack.Push(2);
			stack.Push(3);
			stack.Push(4);
			stack.Push(5);

			Assert::AreEqual(stack.Top(), 5);
		}

		TEST_METHOD(RemoveAllItemsFromList_GetListIsEmpty_Test)
		{
			ArrayStack<int> list;
			list.Push(1);
			list.Pop();


			Assert::IsTrue(list.IsEmpty());
		}

		TEST_METHOD(AddMaxItemsToList_GetListIsFull_Test)
		{
			ArrayStack<int> stack(5);
			stack.Push(1);
			stack.Push(2);
			stack.Push(3);
			stack.Push(4);
			stack.Push(5);

			Assert::IsTrue(stack.IsFull());
		}

		TEST_METHOD(Add5ItemsToList_GetListSize5_Test)
		{
			ArrayStack<int> stack(5);
			stack.Push(1);
			stack.Push(2);
			stack.Push(3);
			stack.Push(4);
			stack.Push(5);

			Assert::AreEqual(stack.Size(), 5);
		}
	};
}
