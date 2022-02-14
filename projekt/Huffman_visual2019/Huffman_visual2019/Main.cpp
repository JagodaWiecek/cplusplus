/** @file */
#include <iostream>
#include <iomanip>
#include <vector>
#include <sstream>
#include <string>
#include <fstream>

#include "Funkcje.h"
#include "Struktury.h"

using namespace std;

int main()
{
	vector<pair<char, int>> tab;

	ifstream out("test.txt");
	int tablica[256]{ 0 };
	char tabl['A'];


	if (out.is_open()) {

		//cout << tabl[0];
		//countchar(out, tablica);
		liczchar(out, tab);
		//sortuj(tab);
		wypisz(tab);
	}
	else {
		cerr << "Blad otwarcia pliku" << endl;
	}
	out.close();
	return 0;
}