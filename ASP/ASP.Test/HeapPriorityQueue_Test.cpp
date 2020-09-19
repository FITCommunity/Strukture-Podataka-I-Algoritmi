#include "pch.h"
#include "CppUnitTest.h"

#include "../ASP/HeapPriorityQueue.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace ASP_Test
{
	TEST_CLASS(HeapPriorityQueue_Test)
	{
	public:

		TEST_METHOD(PeekQueue_GetLargestItemAdded_Test)
		{
			HeapPriorityQueue<int> queue;
			queue.Add(1);
			queue.Add(2);
			queue.Add(3);
			queue.Add(4);
			queue.Add(5);

			Assert::AreEqual(queue.Peek(), 5);
			Assert::AreEqual(queue.Size(), 5);
		}

		TEST_METHOD(RemoveItemFromQueue_RemoveLargestItemAdded_Test)
		{
			HeapPriorityQueue<int> queue;
			queue.Add(1);
			queue.Add(2);
			queue.Add(3);
			queue.Add(4);
			queue.Add(5);

			Assert::AreEqual(queue.Remove(), 5);
			Assert::AreEqual(queue.Size(), 4);
		}

		TEST_METHOD(AddMaxItems_GetQueueIsFull_Test)
		{
			HeapPriorityQueue<int> queue(5);
			queue.Add(1);
			queue.Add(2);
			queue.Add(3);
			queue.Add(4);
			queue.Add(5);

			Assert::IsTrue(queue.IsFull());
		}

		TEST_METHOD(RemoveAllItems_GetQueueIsEmpty_Test)
		{
			HeapPriorityQueue<int> queue;
			queue.Add(1);
			queue.Remove();

			Assert::IsTrue(queue.IsEmpty());
		}
	};
}
