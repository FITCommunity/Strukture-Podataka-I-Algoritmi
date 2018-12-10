#pragma once

#include "Cvor.h"

template <typename Tip>
class PrioritetniRedPov
{
	Cvor<Tip> *prvi;

public:
	PrioritetniRedPov()
		: prvi(nullptr)
	{
	}

	~PrioritetniRedPov()
	{
		while (prvi)
		{
			Cvor<Tip> *temp = prvi;
			prvi = prvi->link;
			delete temp;
		}
	}

	bool isPrazan() const { return !prvi; }

	void Dodaj(const Tip &element)
	{
		Cvor<Tip> *pocetak = prvi;
		Cvor<Tip> *prijePocetka = nullptr;

		while (pocetak)
		{
			if (pocetak->info < element) break;

			prijePocetka = pocetak;
			pocetak = pocetak->link;
		}

		Cvor<Tip> *noviCvor = new Cvor<Tip>(element, pocetak);

		prijePocetka ? prijePocetka->link = noviCvor : prvi = noviCvor;
	}

	Tip Ukloni()
	{
		Cvor<Tip> *tempCvor = prvi;
		prvi = prvi->link;

		Tip temp = tempCvor->info;
		delete tempCvor;
		return temp;
	}
};