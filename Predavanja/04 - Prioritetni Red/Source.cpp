#include <iostream>
#include <ctime>
#include <iomanip>

#include "PrioritetniRedSekv.h"
#include "PrioritetniRedPov.h"
#include "PrioritetniRedHeap.h"


const char *crt = "\n---------------------------------------------------------\n";

int main()
{
	srand(time(0));
#pragma region Sekvencijlani Prioritetni Red

	std::cout << crt;

	PrioritetniRedSekv<int> pRedSekv;
	
	for (int i = 0; i < 10; i++)
	{
		int temp = rand() % 100;
		std::cout << std::setw(2) << temp << " ";
		pRedSekv.Dodaj(temp);
	}

	std::cout << std::endl;
	while (!pRedSekv.isPrazan()) std::cout << std::setw(2) << pRedSekv.Ukloni() << " ";
	std::cout << crt;
#pragma endregion


#pragma region Povezani Prioritetni Red

	std::cout << crt;

	PrioritetniRedPov<int> pRedPov;

	int temp;
	int brojac = 0;
	while (temp = rand() % 100)
	{
		if (brojac && brojac % 10 == 0) std::cout << std::endl;

		std::cout << std::setw(2) << temp << " ";
		pRedPov.Dodaj(temp);
		brojac++;
	}

	std::cout << std::endl;
	brojac = 0;
	while (!pRedPov.isPrazan())
	{
		if (brojac % 10 == 0) std::cout << std::endl;
		std::cout << std::setw(2) << pRedPov.Ukloni() << " ";
		brojac++;
	}
	std::cout << crt;

#pragma endregion

#pragma region Povezani Prioritetni Red

	std::cout << crt;

	try
	{
		PrioritetniRedHeap<int> pRedHeap;

		int temp;
		int brojac = 0;
		while (temp = -(rand() % 100))
		{
			if (brojac && brojac % 10 == 0) std::cout << std::endl;

			std::cout << std::setw(3) << temp << " ";
			pRedHeap.Dodaj(temp);
			brojac++;
		}

		std::cout << std::endl;

		brojac = 0;
		while (!pRedHeap.isPrazan())
		{
			if (brojac % 10 == 0) std::cout << std::endl;
			std::cout << std::setw(3) << pRedHeap.Ukloni() << " ";
			brojac++;
		}

		pRedHeap.Ukloni();
	}
	catch (std::exception e)
	{
		std::cout << std::endl << e.what();
	}

	std::cout << crt;

#pragma endregion

	system("pause>0");
	return 0;
}
