#pragma once
#include "Cvor.h"

template <typename Tip>
class RedPov
{
	Cvor<Tip> *pocetak;
	Cvor<Tip> *kraj;
public:
	RedPov()
		: pocetak(nullptr),
		  kraj(nullptr)
	{
	}

	bool isPrazan() const { return pocetak == nullptr; }

	void Dodaj(const Tip &element)
	{
		Cvor<Tip> *noviCvor = new Cvor<Tip>(element, nullptr);

		if (isPrazan()) pocetak = noviCvor;
		else kraj->link = noviCvor;

		kraj = noviCvor;
	}

	Tip Ukloni()
	{
		if (isPrazan()) throw std::exception("Red je prazan!");

		Cvor<Tip> *tempCvor = pocetak;
		pocetak = pocetak->link;
		
		if (isPrazan()) kraj = nullptr;

		Tip temp = tempCvor->info;
		delete tempCvor;
		return temp;
	}
};
