#pragma once
#include <iostream>

template <typename Tip>
class ListaSekv
{
	int maxVelicina;
	int brojElemenata;
	Tip *niz;

	void prosiriListu()
	{
		Tip *temp = niz;
		niz = new Tip[2 * maxVelicina];
		for (int i = 0; i < maxVelicina; i++) 
			niz[i] = temp[i];
		maxVelicina *= 2;

		delete[] temp;
	}
public:
	ListaSekv(int velicina = 10)
		: maxVelicina(velicina),
		  brojElemenata(0),
		  niz(new Tip[maxVelicina])
	{
	}

	~ListaSekv() 
	{ 
		delete[] niz; 
	}

	void Dodaj(Tip element)
	{
		if (maxVelicina == brojElemenata) prosiriListu();

		niz[brojElemenata++] = element;
	}

	Tip Ukloni()
	{
		if (isPrazan()) throw std::exception("Lista je prazna!");

		Tip temp = niz[--brojElemenata];
		return temp;
	}
	
	Tip &get(int i) const
	{
		if (i < 0)				throw std::exception("Indeks je negativan!");
		if (i >= brojElemenata) throw std::exception("Indeks je veci od broja elemenata!");

		return niz[i];
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

	int getBrojElemenata() const { return brojElemenata; };
	bool isPrazan() const { return brojElemenata == 0; }
};
