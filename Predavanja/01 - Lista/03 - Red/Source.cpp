#include <iostream>
#include "RedPov.h"
#include "RedSekv.h"

const char *crt = "\n-------------------------------------------------------\n";


int main()
{
	std::cout << std::endl << "||||||||||||||||||||| Povezani Red ||||||||||||||||||||" << std::endl;

	RedPov<int> redPov;
#pragma region Test 01 - Dodaj i Ukloni
	try
	{
		std::cout << crt << "Test 01 - Dodaj i Ukloni" << crt;
		for (int i = 0; i < 10; i++)
			redPov.Dodaj(i + 1);
		while (!redPov.isPrazan())
			std::cout << redPov.Ukloni() << " ";
		std::cout << crt;
	}
	catch (std::exception e)
	{
		std::cout << e.what() << std::endl;
	}
#pragma endregion

#pragma region Test 02 - Ukloni nad praznim redom
	try
	{
		std::cout << crt << "Test 02 - Ukloni nad prazmin redom" << crt;
		redPov.Ukloni();
	}
	catch (std::exception e)
	{
		std::cout << e.what() << crt;
	}
#pragma endregion


	std::cout << std::endl << "||||||||||||||||||| Sekvencijalni Red |||||||||||||||||" << std::endl;
	RedSekv<int> redSekv;

#pragma region Test 01 - Dodaj i Ukloni
	try
	{
		std::cout << crt << "Test 01 - Dodaj i Ukloni" << crt;
		for (int i = 0; i < 10; i++)
			redSekv.Dodaj(i + 1);
		while (!redSekv.isPrazan())
			std::cout << redSekv.Ukloni() << " ";
		std::cout << crt;
	}
	catch (std::exception e)
	{
		std::cout << e.what() << std::endl;
	}
#pragma endregion

#pragma region Test 02 - Ukloni nad praznim redom
	try
	{
		std::cout << crt << "Test 02 - Ukloni nad prazmin redom" << crt;
		redSekv.Ukloni();
	}
	catch (std::exception e)
	{
		std::cout << e.what() << crt;
	}
#pragma endregion

	system("pause>0");
	return 0;
}