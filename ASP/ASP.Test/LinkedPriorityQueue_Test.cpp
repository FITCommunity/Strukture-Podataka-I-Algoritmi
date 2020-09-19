#include "pch.h"
#include "CppUnitTest.h"

#include "../ASP/LinkedPriorityQueue.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace ASP_Test
{
	TEST_CLASS(LinkedPriorityQueue_Test)
	{
	public:

		TEST_METHOD(PeekQueue_GetLargestItemAdded_Test)
		{
			LinkedPriorityQueue<int> queue;
			queue.Add(1);
			queue.Add(2);
			queue.Add(3);
			queue.Add(4);
			queue.Add(5);

			Assert::AreEqual(queue.Peek(), 5);
		}

		TEST_METHOD(RemoveItemFromQueue_RemoveLargestItemAdded_Test)
		{
			LinkedPriorityQueue<int> queue;
			queue.Add(1);
			queue.Add(2);
			queue.Add(3);
			queue.Add(4);
			queue.Add(5);

			Assert::AreEqual(queue.Remove(), 5);
		}


		TEST_METHOD(RemoveAllItems_GetQueueIsEmpty_Test)
		{
			LinkedPriorityQueue<int> queue;
			queue.Add(1);
			queue.Remove();

			Assert::IsTrue(queue.IsEmpty());
		}

	};
}
