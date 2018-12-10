#pragma once

template<typename Tip>
void Merge
(
	Tip *niz,
	int pocetak,
	int sredina,
	int kraj,
	std::function<bool(const Tip&, const Tip&)> cmp = [](const Tip &x, const Tip &y) {return x < y; }
)
{
	int iPocetakTempNiz = 0;
	int iPocetak1 = pocetak;
	int iPocetak2 = sredina + 1;
	int duzina = kraj - pocetak + 1;

	Tip *tempNiz = new Tip[duzina];

	//Spoji 2 niza
	while (iPocetak1 <= sredina && iPocetak2 <= kraj)
		cmp(niz[iPocetak1], niz[iPocetak2]) ? tempNiz[iPocetakTempNiz++] = niz[iPocetak1++]
											: tempNiz[iPocetakTempNiz++] = niz[iPocetak2++];


	//Kopiraj ostatak
	while (iPocetak1 <= sredina)
		tempNiz[iPocetakTempNiz++] = niz[iPocetak1++];
	while (iPocetak2 <= kraj)
		tempNiz[iPocetakTempNiz++] = niz[iPocetak2++];


	//Kopiraj temp niz u orginal
	for (int i = pocetak, j = 0; i <= kraj; i++, j++)
		niz[i] = tempNiz[j];

	delete[] tempNiz;

}

template<typename Tip>
void MSort
(
	Tip *niz,
	int pocetak,
	int kraj,
	std::function<bool(const Tip&, const Tip&)> cmp = [](const Tip &x, const Tip &y) {return x < y; }
)
{
	if (pocetak < kraj)
	{
		int sredina = (pocetak + kraj) / 2;
		MSort(niz, pocetak, sredina, cmp);
		MSort(niz, sredina + 1, kraj, cmp);

		Merge(niz, pocetak, sredina, kraj, cmp);
	}
}

template<typename Tip>
void MergeSort
(
	Tip *niz,
	int duzina,
	std::function<bool(const Tip&, const Tip&)> cmp = [](const Tip &x, const Tip &y) {return x < y; }
)
{
	MSort(niz, 0, duzina - 1, cmp);
}