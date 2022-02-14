/** @file */
#ifndef FUNKCJE_H
#define FUNKCJE_H

#include <iostream>
#include <iomanip>
#include <vector>
#include <sstream>
#include <string>
#include <fstream>
#include "Struktury.h"

using namespace std;

void liczchar(ifstream& plik, vector<pair<char, int>>& vector);

void wypisz(vector<pair<char, int>>tab);

void sortuj(vector<pair<char, int>>& vec);

void countchar(ifstream& plik, int* tab);

#endif
