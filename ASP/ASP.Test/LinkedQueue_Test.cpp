#include "pch.h"
#include "CppUnitTest.h"

#include "../ASP/LinkedQueue.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace ASP_Test
{
	TEST_CLASS(LinkedQueue_Test)
	{
	public:

		TEST_METHOD(PeekQueue_GetFirstItemAdded_Test)
		{
			LinkedQueue<int> queue;
			queue.Add(1);
			queue.Add(2);
			queue.Add(3);
			queue.Add(4);
			queue.Add(5);

			Assert::AreEqual(queue.Peek(), 1);
		}

		TEST_METHOD(RemoveItemFromQueue_RemoveFirstItemAdded_Test)
		{
			LinkedQueue<int> queue;
			queue.Add(1);
			queue.Add(2);
			queue.Add(3);
			queue.Add(4);
			queue.Add(5);

			Assert::AreEqual(queue.Remove(), 1);
		}


		TEST_METHOD(RemoveAllItems_GetQueueIsEmpty_Test)
		{
			LinkedQueue<int> queue;
			queue.Add(1);
			queue.Remove();

			Assert::IsTrue(queue.IsEmpty());
		}

	};
}
