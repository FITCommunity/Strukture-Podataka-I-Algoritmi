#pragma once
#include <functional>



namespace
{
	template<typename T, typename F = std::function<bool(const T&, const T&)>>
	int Partition
	(
		T* array,
		int beginning,
		int ending,
		const F& compare = [](const T& x, const T& y) {return x < y; }
	)
	{
		T pivot = array[ending];
		int i = beginning;

		for (int j = beginning; j < ending; j++)
		{
			if (compare(array[j], pivot))
			{
				std::swap(array[i], array[j]);
				i++;
			}
		}

		std::swap(array[i], array[ending]);

		return i;

	}

	template<typename T, typename F = std::function<bool(const T&, const T&)>>
	void QSort
	(
		T* array,
		int beginning,
		int ending,
		const F& compare = [](const T& x, const T& y) {return x < y; }
	)
	{
		if (beginning < ending)
		{
			int pivot = Partition(array, beginning, ending, compare);

			QSort(array, beginning, pivot - 1, compare);
			QSort(array, pivot + 1, ending, compare);
		}
	}
}

template<typename T, typename F = std::function<bool(const T&, const T&)>>
void QuickSort
(
	T* array,
	int size,
	const F& compare = [](const T& x, const T& y) {return x < y; }
)
{
	QSort(array, 0, size - 1, compare);
}