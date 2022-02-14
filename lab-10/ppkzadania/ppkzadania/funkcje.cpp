#include <iostream>
#include <vector>
#include <iomanip>
#include <cstdlib>
#include <fstream>
#include <sstream>

using namespace std;
#include "funkcje.h"



void przypisz(const string& tekst, macierz &tab)
{
	ifstream odczyt(tekst);
	
	if (odczyt)
	{
		string wiersz;
		while (getline(odczyt, wiersz))
		{
			vector<double> wiersze_w_m;
			stringstream ss;
			ss << wiersz;
			double liczba;

			while (ss>>liczba)
			{
				wiersze_w_m.push_back(liczba);

			}
			tab.m.push_back(wiersze_w_m);

		}
	}
}
void wyp(macierz tab)
{
	
	for (int i = 0; i < tab.m.size(); i++)
	{
		for (int j = 0; j < tab.m[i].size(); j++)
		{
			cout << tab.m[i][j];
		}
	}
}