#include <iostream>
#include "ListaSekv.h"
#include "ListaPov.h"

const char *crt = "\n-------------------------------------------------------\n";

void SekvencijalnaListaTest()
{
	std::cout << std::endl << "||||||||||||||||| Sekvencijalna Lista |||||||||||||||||" << std::endl;
	ListaSekv<int> lista;
	for (int i = 0; i < 10; i++)
		lista.Dodaj(i);

#pragma region Test 01 - Ispisi sa get()
	try
	{
		std::cout << crt << "Test 01 - Ispisi sa get()" << crt;
		int brojElemenata = lista.getBrojElemenata();
		for (int i = 0; i < brojElemenata; i++)
			std::cout << lista.get(i) << " ";
		std::cout << crt;
	}
	catch (std::exception e)
	{
		std::cout << e.what();
	}
#pragma endregion

#pragma region Test 02 - Indeks veci od brojaElemenata
	try
	{
		std::cout << crt << "Test 02 - Indeks veci od brojaElemenata" << crt;
		int brojElemenata = lista.getBrojElemenata();
		for (int i = 0; i < brojElemenata + 1; i++)
			std::cout << lista.get(i) << " ";
		std::cout << crt;
	}
	catch (std::exception e)
	{
		std::cout << e.what() << crt;
	}
#pragma endregion

#pragma region Test 03 - Negativan indeks
	try
	{
		std::cout << crt << "Test 03 - Negativan indeks" << crt;
		std::cout << crt << lista.get(-1) << crt;
	}
	catch (std::exception e)
	{
		std::cout << crt << e.what() << crt;
	}
#pragma endregion

#pragma region Test 04 - Prosiri listu
	try
	{
		std::cout << crt << "Test 04 - Prosiri listu" << crt;
		for (int i = 0; i < 15; i++)
			lista.Dodaj(i + 10);
		int brojElemenata = lista.getBrojElemenata();
		for (int i = 0; i < brojElemenata; i++)
			std::cout << lista.get(i) << " ";
		std::cout << crt;
	}
	catch (std::exception e)
	{
		std::cout << e.what();
	}
#pragma endregion

#pragma region Test 05 - Ukloni elemente
	try
	{
		std::cout << crt << "Test 05 - Ukloni elemente" << crt;
		for (int i = 0; i < 15; i++)
			std::cout << lista.Ukloni() << std::endl;
		int brojElemenata = lista.getBrojElemenata();
		for (int i = 0; i < brojElemenata; i++)
			std::cout << lista.get(i) << " ";
		std::cout << crt;
	}
	catch (std::exception e)
	{
		std::cout << e.what();
	}
#pragma endregion

#pragma region Test 05 - Ukloni iz prazne liste
	try
	{
		std::cout << crt << "Test 05 - Ukloni iz prazne liste" << crt;
		while (!lista.isPrazan()) lista.Ukloni();
		lista.Ukloni();
	}
	catch (std::exception e)
	{
		std::cout << e.what() << crt;
	}
#pragma endregion

#pragma region Test 06 - Pokazivaci
	try
	{
		std::cout << crt << "Test 06 - Pokazivaci" << crt;
		ListaSekv<int*> listaPokazivaca;
		for (int i = 0; i < 10; i++)
			lista.Dodaj(i), listaPokazivaca.Dodaj(&lista.get(i));
		for (int i = 0; i < 10; i++)
			std::cout << listaPokazivaca.get(i) << " " << *listaPokazivaca.get(i) << std::endl;
		std::cout << crt;
	}
	catch (std::exception e)
	{
		std::cout << e.what();
	}
#pragma endregion

#pragma region Test 07 - Promjena vrijednosti elementa preko set()
	try
	{
		std::cout << crt << "Test 07 - Promjena vrijednosti elementa preko set()" << crt;
		int brojElemenata = lista.getBrojElemenata();
		for (int i = 0; i < 10; i++)
			lista.set(i, brojElemenata - i);
		for (int i = 0; i < 10; i++)
			std::cout << lista.get(i) << " ";
		std::cout << crt;
	}
	catch (std::exception e)
	{
		std::cout << e.what();
	}
#pragma endregion
}
void PovezanaListaTest()
{
	std::cout << std::endl << "||||||||||||||||||| Povezana Lista ||||||||||||||||||||" << std::endl;
	ListaPov<int> lista;

#pragma region Test 01 - Dodaj na pocetak
	try
	{
		std::cout << crt << "Test 01 - Dodaj na pocetak" << crt;
		for (int i = 0; i < 10; i++)
			lista.DodajPrvi(i);
		for (int i = 0; i < 10; i++)
			std::cout << lista.get(i) << " ";
		std::cout << crt;
	}
	catch (std::exception e)
	{
		std::cout << e.what();
	}
#pragma endregion

#pragma region Test 02 - Dodaj na kraj
	try
	{
		std::cout << crt << "Test 01 - Dodaj na pocetak" << crt;
		int brojElemenata = lista.getBrojElemenata();
		for (int i = 0; i < brojElemenata; i++)
			lista.DodajPosljednji(brojElemenata - 1 - i);

		brojElemenata = lista.getBrojElemenata();
		for (int i = 0; i < brojElemenata; i++)
			std::cout << lista.get(i) << " ";
		std::cout << crt;
	}
	catch (std::exception e)
	{
		std::cout << e.what();
	}
#pragma endregion
}

int main()
{
	SekvencijalnaListaTest();
	PovezanaListaTest();

	system("pause>0");
	return 0;
}