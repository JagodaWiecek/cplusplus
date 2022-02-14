/** @file */
#include <iostream>
#include <iomanip>
#include <vector>
#include <sstream>
#include <string>
#include <fstream>
#include <chrono>

#include "Funkcje.h"
#include "Struktury.h"

using namespace std;

void liczchar(ifstream& plik, vector<pair<char, int>>& vec)
{
	string tekst;
	while (getline(plik, tekst))
	{
		tekst += '\0';
		for (int i = 0; i < tekst.length(); i++)
		{
			bool jest = false;
			for (int j = 0; j < vec.size() && !jest; j++)
			{
				if (tekst[i] == vec[j].first)
				{
					vec[j].second++;
					jest = true;
				}
			}
			if (!jest)
			{
				pair <char, int> chwila;
				chwila.first = tekst[i];
				chwila.second = 1;
				vec.push_back(chwila);
			}
		}
	}
	plik.close();
}



void wypisz(vector<pair<char, int>>tab)
{
	for (int i = 0; i < tab.size(); i++)
	{
		cout << "[ " << tab[i].first << " ] = " << tab[i].second;
		cout << endl;
	}
}

void countchar(ifstream& plik, int* tab)
{
	char buf[1000];

	while (plik.read(buf, 1000))
	{
		for (int i = 0; i < 1000; i++)
		{
			cout << buf[i] << " " << (int)buf[i] << endl;
			tab[buf[i]]++;
		}
	}

}

void sortuj(vector<pair<char, int>>& vec)
{
	int max;
	char z;
	for (int i = 0; i < vec.size(); i++)
	{
		int idx = i;
		for (int j = i + 1; j < vec.size(); j++)
		{
			if (vec[j].second < vec[idx].second)
			{
				idx = j;
			}
		}
		max = vec[idx].second;
		z = vec[idx].first;
		vec[idx].second = vec[i].second;
		vec[idx].first = vec[i].first;
		vec[i].second = max;
		vec[i].first = z;
	}
}