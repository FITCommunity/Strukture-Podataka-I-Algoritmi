#include <iostream>
#include <string>

#include "OpenAddress_Hash.h"
#include "Chained_Hash.h"


int main()
{
	OpenAddress_Hash<std::string, std::string> rjecnik;
	std::string temp[3]{ "Programiranje", "Algoritam", "Strukture podataka" };

	rjecnik.Dodaj("Programiranje", "Programming");
	rjecnik.Dodaj("Algoritam", "Algorithm");
	rjecnik.Dodaj("Strukture podataka", "Data structures");

	for (int i = 0; i < 3; i++)
	{
		auto tempS = rjecnik.Get(temp[i]);
		if (tempS) std::cout << tempS->getKljuc() << " - " << tempS->getVrijednost() << std::endl;
	}

	std::cout << std::endl;
	rjecnik.Ukloni("Algoritam");

	for (int i = 0; i < 3; i++)
	{
		auto tempS = rjecnik.Get(temp[i]);
		if (tempS) std::cout << tempS->getKljuc() << " - " << tempS->getVrijednost() << std::endl;
	}

	std::cout << std::endl;

	Chained_Hash<int, int> mapa;
	mapa.Dodaj(1, 1);
	mapa.Dodaj(1, 2);
	mapa.Dodaj(2, 2);
	mapa.Dodaj(3, 3);

	auto tempC = mapa.Get(1, 2);
	if (tempC) std::cout << tempC->getKljuc() << " - " << tempC->getVrijednost() << std::endl;

	auto tempB = mapa.Get(0, 0);
	if (tempB) std::cout << tempB->getKljuc() << " - " << tempB->getVrijednost() << std::endl;

	system("pause>0");
	return 0;
}