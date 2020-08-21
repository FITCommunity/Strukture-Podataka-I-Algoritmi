#pragma once
#include <functional>
#include "HashNode.h"

template<typename Kljuc, typename Vrijednost>
class OpenAddress_Hash
{
	int maxVelicina;
	HashNode<Kljuc, Vrijednost> **niz;
	int brojElemenata;

	int getHash(const Kljuc &kljuc) const
	{
		return std::hash<Kljuc>{}(kljuc) % maxVelicina;
	}
public:
	OpenAddress_Hash(int max = 10) : maxVelicina(max)
	{
		niz = new HashNode<Kljuc, Vrijednost>*[max];
		for (int i = 0; i < maxVelicina; i++)
			niz[i] = nullptr;
		brojElemenata = 0;
	}

	~OpenAddress_Hash()
	{
		for (int i = 0; i < maxVelicina; i++)
			delete niz[i];
		delete[] niz;
	}

	bool isPun() const { return brojElemenata == maxVelicina; }
	bool isPrazan() const { return brojElemenata == 0; }

	void Dodaj(const Kljuc &kljuc, const Vrijednost &vrijednost)
	{
		if (isPun()) throw std::exception("Greska, nema vise prostora!");

		int i = getHash(kljuc);
		int pocetni = i;
		while (niz[i])
		{
			i++;
			if (i == maxVelicina) i = 0;

			if (i == pocetni) return;
		}

		niz[i] = new HashNode<Kljuc, Vrijednost>(kljuc, vrijednost);
		brojElemenata++;
	}

	bool Ukloni(const Kljuc &kljuc)
	{
		if (isPrazan()) return false;

		int i = getHash(kljuc);
		int pocetni = 0;
		while (1)
		{
			if (niz[i] && niz[i]->getKljuc() == kljuc)
			{
				brojElemenata--;
				delete niz[i];
				niz[i] = nullptr;
				return true;
			}

			i++;
			if (i == maxVelicina) i = 0;
			if (i == pocetni) break;
		}

		return false;
	}

	HashNode<Kljuc, Vrijednost> *Get(const Kljuc &kljuc)
	{
		if (isPrazan()) return nullptr;

		int i = getHash(kljuc);
		int pocetni = i;
		while (1)
		{
			if (niz[i] && niz[i]->getKljuc() == kljuc) 
				return niz[i];
			

			i++;
			if (i == maxVelicina) i = 0;

			if (i == pocetni) return nullptr;
		}
 	}
};