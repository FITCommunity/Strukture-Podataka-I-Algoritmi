#pragma once
#include <functional>

template<typename Tip>
void InsertionSort
(
	Tip *niz,
	int velicina,
	std::function<bool(const Tip&, const Tip&)> cmp = [](const Tip &x, const Tip &y) {return x > y; }
)
{
	for (int i = 1; i < velicina; i++)
	{
		int j = i;
		while (j > 0 && cmp(niz[j - 1], niz[j]))
		{
			std::swap(niz[j - 1], niz[j]);
			j--;
		}
	}
}