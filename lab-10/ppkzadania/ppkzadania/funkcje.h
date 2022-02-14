#include <iostream>
#include <vector>
#include <iomanip>
#include <cstdlib>
#include <fstream>
#include <sstream>

#ifndef funckje_h
#define funckje_h

struct macierz {
	vector<vector<double>> m;
};
void przypisz(const std::string& tekst, macierz& tab);
void wyp(macierz tab);
#endif // !funckje_h

