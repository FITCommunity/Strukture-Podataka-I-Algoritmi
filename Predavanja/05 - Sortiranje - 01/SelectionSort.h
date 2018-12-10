#pragma once
#include <functional>

template<typename Tip>
void SelectionSort
(
	Tip *niz,
	int velicina,
	std::function<bool(const Tip&, const Tip&)> cmp = [](const Tip &x, const Tip &y) {return x < y; }
)
{
	for (int i = 0; i < velicina - 1; i++)
	{
		int indeks = i;
		for (int j = i + 1; j < velicina; j++)
			if (cmp(niz[j], niz[indeks]))
				indeks = j;

		if (indeks != i)
			std::swap(niz[indeks], niz[i]);
	}
}