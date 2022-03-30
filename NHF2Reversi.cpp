// NHF2Reversi.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <cstddef>

#include <sstream>
#include <string>

#include "jatek.h"
#include "konzol.h"

int main()
{
	string tempBemenet;
	do
	{
		cout << "Menu:\n0 -> kilepes\n1 -> teszt futtatasa legrovidebb fekete gyozelemmel\n2 -> jatek inditasa\nadjon meg egy 0-2 szamot:";
		cin >> tempBemenet;
		if (tempBemenet == "1")
		{
			const char* kimenetNeve = "konzol1";
			Konzol K(kimenetNeve, std::cout);
			//legrövidebb lehetséges játék lépései teszteléshez: D3 C5 D6 E3 B4 C3 D2 C4 F4
			istringstream testInput("A1\nABCD1234hosszteszt\nK9\nD3\nC5\nD6\nE3\nB4\nC3\nD2\nC4\nF4\n");
			Jatek J(&K, testInput);
			J.Start();
		}
		else if (tempBemenet == "2")
		{
			const char* kimenetNeve = "konzol1";
			Konzol K(kimenetNeve, std::cout);
			Jatek J(&K, cin);
			J.Start();
		}

	} while (tempBemenet != "0");
}

