#include <iostream>
#include "StekSekv.h"
#include "StekPov.h"

const char *crt = "\n-------------------------------------------------------\n";

void SekvencijalniStekTest()
{
	std::cout << std::endl << "||||||||||||||||| Sekvencijalni Stek ||||||||||||||||||" << std::endl;

#pragma region Test 01 - Push i Pop
	try
	{
		std::cout << crt << "Test 01 - Push i Pop" << crt;

		StekSekv<int> stek;
		for (int i = 0; i < 10; i++)
			stek.Push(i);
		while(!stek.isPrazan())
			std::cout << stek.Pop() << " ";
		std::cout << crt;
	}
	catch (std::exception e)
	{
		std::cout << e.what();
	}
#pragma endregion

#pragma region Test 02 - Top prazan stek
	try
	{
		std::cout << crt << "Test 02 - Top prazan stek" << crt;
		StekSekv<int> stek;
		for (int i = 0; i < 10; i++)
			stek.Push(10 * i);
		while (!stek.isPrazan())
			std::cout << stek.Pop() << " ";
		stek.Top();
		std::cout << crt;
	}
	catch (std::exception e)
	{
		std::cout << e.what() << crt;
	}
#pragma endregion

}

void PovezaniStekTest()
{
	std::cout << std::endl << "||||||||||||||||||| Povezani Stek |||||||||||||||||||||" << std::endl;

#pragma region Test 01 - Push i Pop
	try
	{
		std::cout << crt << "Test 01 - Push i Pop" << crt;

		StekPov<int> stek;
		for (int i = 0; i < 10; i++)
			stek.Push(i);
		while (!stek.isPrazan())
			std::cout << stek.Pop() << " ";
		std::cout << crt;
	}
	catch (std::exception e)
	{
		std::cout << e.what();
	}
#pragma endregion

#pragma region Test 02 - Top prazan stek
	try
	{
		std::cout << crt << "Test 02 - Top prazan stek" << crt;
		StekPov<int> stek;
		for (int i = 0; i < 10; i++)
			stek.Push(10 * i);
		while (!stek.isPrazan())
			std::cout << stek.Pop() << " ";
		stek.Top();
		std::cout << crt;
	}
	catch (std::exception e)
	{
		std::cout << e.what() << crt;
	}
#pragma endregion
}

void TestStekove()
{
	std::cout << std::endl << "|||||||||||||||||||||| Test Stek ||||||||||||||||||||||" << std::endl;

#pragma region Test 01 - Konverzija iz Povezanog u Sekvencijalni
	try
	{
		std::cout << crt << "Test 01 - Konverzija iz Povezanog u Sekvencijalni" << crt;

		StekPov<int> stekPov;
		for (int i = 0; i < 10; i++)
			stekPov.Push(i + 1);

		StekSekv<int> stekSekv;
		std::cout << "Povezani stek: ";
		while (!stekPov.isPrazan())
		{
			std::cout << stekPov.Top() << " ";
			stekSekv.Push(stekPov.Pop());
		}

		std::cout << std::endl << "Sekvencijalni stek: ";
		while (!stekSekv.isPrazan())
			std::cout << stekSekv.Pop() << " ";

		std::cout << crt;
	}
	catch (std::exception e)
	{
		std::cout << e.what() << std::endl;
	}
#pragma endregion

#pragma region Test 02 - Konverzija iz Sekvencijalnog u Povezani
	try
	{
		std::cout << crt << "Test 02 - Konverzija iz Sekvencijalnog u Povezani" << crt;

		StekSekv<int> stekSekv;
		for (int i = 0; i < 10; i++)
			stekSekv.Push(i + 1);

		StekSekv<int> stekPov;
		std::cout << "Sekvencijalni stek: ";
		while (!stekSekv.isPrazan())
		{
			std::cout << stekSekv.Top() << " ";
			stekPov.Push(stekSekv.Pop());
		}

		std::cout << std::endl << "Povezani stek: ";
		while (!stekPov.isPrazan())
			std::cout << stekPov.Pop() << " ";

		std::cout << crt;
	}
	catch (std::exception e)
	{
		std::cout << e.what() << std::endl;
	}
#pragma endregion

}

int main()
{
	SekvencijalniStekTest();
	PovezaniStekTest();
	TestStekove();

	system("pause>0");
	return 0;
}