/**file*/
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


/**Funkcja majaca na celu zczytac birarnie litery z pliku do tablicy poprzez bufor. Kazda litera jest zapisana z tablicy ascii jako int.
 @param tab - tablica wczytujaca znaki jako inty na podstwawie tablicy ascii.*/
void countchar(ifstream& plik, int* tab);

///funckja przepisujaca zawartosc tablicy do vectora node.
///Zawartosc przepisuje jako licznik a indeks komorki jako znak
/// @param *tab tablica int
/// @param vec - vector struktury node 
void przep(int* tab, vector<node>& vec);

/**Funckja tworzy drzewo z vectora node. Do wskaznikow skruktury sa przypisane ostatnie wartosci vectora,
 po czym sa one sumowane i wrzucane do zmiennej pomocniczej "temp". Nastepnie ostatnie te wartosci sa usuwane z listy i jest wrzucany temp do wektora.
  czynnosc sie ta powtarza tak dlugo, az w vectorze nie zostanie ostatnia wartosc, czyli glowny korzen.*/ 
void drzewo(vector<node>& tab);

/// Funckja nadajaca rekurencyjnie kod zero-jedynkowy typu string kazdemu znakowi.
///przechodzi od korzenia tak dlugo, dopuki galaz lewa i prawa nie beda nullptr.
/// @param korz pierwsza wartosc vectora 
/// @param code poczatkowy kod string
/// @param kod vector do ktorego sa zapisywane informacje o kodzie i literach
void rek(node* korz, string code, vector<key>& kod);

///Funckja wpisyjaca do pliku zawartosc vectora klucz.
/// @param plik - plik do ktorego jest zapisywany klucz, znaki sa zapisane kodem ascii
/// @param klucz - vector w ktorym sa zapisane kody
void wypK(ofstream& plik, vector<key>klucz);

/// funkcja ma analizowac pojedynczo litery z pliku wejsciowego, porownywac z vectorem klucz
/// i na podstawie tego przepisywac do pliku wyjsciowego kod zawarty w vectorze
/// @param plik - plik wejsciowy
/// @param inp - plik wyjsciowy
/// @param klucz - vector struktury, zawiera w zobie znaki i kody do znakow
void koduj(ifstream& plik, ofstream& inp, vector<key>klucz);


/// Funckja przepisuje zawartosc z pliku wejsciowego do vectora, wykorzystywane go dekodowania
/// @param plik - plik wejsciowy
/// @param k - vector struktury, majacy przechowywac dane z pliku
void przepklucz(ifstream& plik, vector<klucz>& k);

/// <summary>
/// funkcja bada po kolei dlugosci zero-jedynkowych tekstow, jak odpowiednia dlugosc bedzie sie zgadzac z kluczem, to wypisze ja do pliku wyjsciowego
/// <summary>
/// <param name="plik">plik wejsciowy</param>
/// <param name="inp">plik wyjsciowy</param>
/// <param name="k">vector klucza</param>
void odszyfr(ifstream& plik, ofstream& inp, vector<klucz> k);

#endif
