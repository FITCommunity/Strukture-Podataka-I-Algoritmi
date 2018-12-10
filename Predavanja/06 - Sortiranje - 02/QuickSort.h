#pragma once
#include <functional>

template<typename Tip>
int Particija
(
	Tip *niz,
	int pocetak,
	int kraj,
	std::function<bool(const Tip&, const Tip&)> cmp = [](const Tip &x, const Tip &y) {return x < y; }
)
{
	Tip pivot = niz[kraj];
	int i = pocetak - 1;

	for (int j = pocetak; j < kraj; j++)
	{
		if (cmp(niz[j], pivot))
		{
			i++;
			std::swap(niz[i], niz[j]);
		}
	}

	i++;
	std::swap(niz[i], niz[kraj]);

	return i;
}

template<typename Tip>
void QSort
(
	Tip *niz,
	int pocetak,
	int kraj,
	std::function<bool(const Tip&, const Tip&)> cmp = [](const Tip &x, const Tip &y) {return x < y; }
)
{
	if (pocetak < kraj)
	{
		int pivot = Particija(niz, pocetak, kraj, cmp);

		QSort(niz, pocetak, pivot - 1);
		QSort(niz, pivot + 1, kraj);
	}
}

template<typename Tip>
void QuickSort
(
	Tip *niz,
	int duzina,
	std::function<bool(const Tip&, const Tip&)> cmp = [](const Tip &x, const Tip &y) {return x < y; }
)
{
	QSort(niz, 0, duzina, cmp);
}