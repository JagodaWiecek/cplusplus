#include <iostream>
#include <vector>
#include <iomanip>
#include <cstdlib>
#include <fstream>
#include <sstream>

using namespace std;
#include "funkcje.h"

int main()
{
	macierz vec;
	ofstream plik("odczytana");
	przypisz("macierz.txt",vec);
	wyp(vec);

	plik.close();
}

