#pragma once
#include "Cvor.h"

template <class Tip>
class ListaPov
{
	int brojElemenata;
	Cvor<Tip> *prvi;
public:
	ListaPov()
		: brojElemenata(0),
		  prvi(nullptr)
	{
	}

	~ListaPov()
	{
		while (prvi)
		{
			Cvor<Tip> *temp = prvi;
			prvi = prvi->link;
			delete temp;
		}
	}

	void DodajPrvi(Tip element)
	{
		Cvor<Tip>* novi = new Cvor<Tip>(element, prvi);
		prvi = novi;
		brojElemenata++;
	}

	Tip UkloniPrvi()
	{
		if (isPrazan()) throw std::exception("Lista je prazna!");

		brojElemenata--;

		Cvor<Tip> *tempPrvi = prvi;
		prvi = prvi->next;

		Tip temp = tempPrvi->info;
		delete tempPrvi;
		return temp;
	}

	void DodajPosljednji(Tip element)
	{
		brojElemenata++;

		Cvor<Tip> *noviCvor = new Cvor<Tip>(element, nullptr);

		if (!prvi)
		{
			prvi = noviCvor;
			return;
		}

		Cvor<Tip> *pocetak = prvi;
		while (pocetak->link) pocetak = pocetak->link;
		pocetak->link = noviCvor;
	}

	Tip UkloniPosljednji()
	{
		if (isPrazan()) throw std::exception("Lista je prazna!");

		brojElemenata--;

		Cvor<Tip> *pocetak = prvi;
		Cvor<Tip> *prijePocetka = nullptr;

		while (pocetak)
		{
			prijePocetka = pocetak;
			pocetak = pocetak->link;
		}

		if (prijePocetka) prijePocetka->link = nullptr;
		else prvi = nullptr;

		Tip temp = pocetak->info;
		delete pocetak;
		return temp;
	}

	bool isPrazan() const { return !prvi; }
	int getBrojElemenata() const { return brojElemenata; }

	Tip &get(int i) const
	{
		if (i < 0)				throw std::exception("Indeks je negativan!");
		if (i >= brojElemenata) throw std::exception("Indeks je veci od broja elemenata!");

		Cvor<Tip>* pocetak = prvi;
		for (int j = 0; j < i; j++)
			pocetak = pocetak->link;
		return pocetak->info;
	}

	void set(int i, Tip vrijednost)
	{
		try
		{
			get(i) = vrijednost;
		}
		catch (std::exception e)
		{
			throw e;
		}
	}

	bool Sadrzi(Tip element) const
	{
		Cvor<Tip> *temp = prvi;
		while (temp)
		{
			if (temp->info == element) return true;
			temp = temp->link;
		}

		return false;
	}
};