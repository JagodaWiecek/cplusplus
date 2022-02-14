/** @file */

/*
   PODSTAWY PROGRAMOWANIA KOMPUTERÓW

   wykład 7: strumienie   

 */

#include <iostream> 
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <chrono>
#include <random>

#include "funkcje.h"

double los ()
{
	static std::default_random_engine silnik (std::chrono::system_clock::now().time_since_epoch().count());
	std::normal_distribution<double> wzrost (170, 15);

	return wzrost (silnik);
}

void zapisz_macierz(const std::string& NAZWA_PLIKU, const int LICZBA_KOLUMN, const int LICZBA_WIERSZY)
{
	std::ofstream plik (NAZWA_PLIKU);
	if (plik)
	{
		for (int w = 0 ; w < LICZBA_WIERSZY; w++)  // dla kazdego wiersza
		{
			for (int k = 0; k < LICZBA_KOLUMN; k++) // dla kazdej kolumny w wierszu
				plik << los() << " ";
			plik << std::endl; // wiersz konczymy znakiem nowej linii
		}
	}
}

std::vector<std::vector<double>> odczytaj_macierz(const std::string& NAZWA_PLIKU)
{
	std::vector<std::vector<double>> macierz;
	std::ifstream plik (NAZWA_PLIKU);
	if (plik)
	{
		std::string wiersz; // tekst

		while (getline(plik, wiersz))   // wczytuje caly wiersz
		{
			// std::cout << "[" << wiersz << "]" << std::endl; // wypisane kontrolne
			// mamy liczby w wierszu zapisane jako tekst 

			std::vector<double> liczby_w_wierszu_macierzy;
			std::stringstream ss; 
			ss << wiersz;
			double liczba;  // liczba zmiennoprzecinkowa

			while (ss >> liczba)
			{
				// std::cout << "[" << liczba << "] "; 
				liczby_w_wierszu_macierzy.push_back(liczba);
			}
			//  std::cout << std::endl;
			macierz.push_back(liczby_w_wierszu_macierzy);

		}
	}
	return macierz;  
}
