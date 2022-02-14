/** @file */

/*
   PODSTAWY PROGRAMOWANIA KOMPUTERÓW

   wykład 7

 */
#ifndef FUNKCJE_H
#define FUNKCJE_H

#include <string>
#include <vector>

/** Funkcja zapisuje macierz do pliku.
 * @param NAZWA_PLIKU nazwa pliku :-)
 * @param LICZBA_KOLUMN liczba kolumn
 * @param LICZBA_WIERSZY liczba wierszy
 *   
 */
void zapisz_macierz(const std::string & NAZWA_PLIKU, const int LICZBA_KOLUMN, const int LICZBA_WIERSZY);

/** Funkcja odczytuje macierz z pliku tekstowego. Każdy wiersz macierzy jest w osobnym wierszu w pliku. Liczby są rozdzielone białymi znakami.
 * @param NAZWA_PLIKU nazwa pliku z macierzą 
 * @return wektor wierszy, kazdy wiersz jest reprezentowany przez wektor liczb
 */ 
std::vector<std::vector<double>>  odczytaj_macierz (const std::string & NAZWA_PLIKU);

/** @return losowa wartosc z rozkladu normalnego N(170,15). */
double los(); 

#endif
