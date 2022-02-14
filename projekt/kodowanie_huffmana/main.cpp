/**file*/
#include <iostream>
#include <iomanip>
#include <vector>
#include <sstream>
#include <string>
#include <fstream>
#include <algorithm>
#include <cstdlib>

#include "Funkcje.h"
#include "Struktury.h"


using namespace std;

/**  Funkcja main, punkt wyjœcia do wykonywania programu

@param  argc liczba parametrow przy uruchomieniu programu
@param  argv tablica wskaznikow na lancuchy uzytych przy uruchomienieu programu

@return jeœli program wykona³ siê prawid³owo zwracane jest 0
*/
	
int main(int argc, const char* argv[])
{

	string file_in, file_out, mod, cod;
	string napis;
	if (argc ==9)
	{
		for (int i = 0; i < argc-1; i++)
		{ 
			napis = argv[i];
			if (napis == "-o")
			{
				file_out = argv[i + 1];
			}
			else if (napis == "-i")
			{
				file_in = argv[i + 1];
			}
			else if (napis == "-t")
			{
				mod = argv[i + 1];
			}
			else if (napis == "-s")
			{
				cod = argv[i+1];
			}
		}
		
	}
	else
	{
		cout << "Potrzebne parametry do poprawnego wlaczenia programu\n-i \tplik wejsciowy \n-o \tplik wyjsciowy \n-s \tplik ze slownikiem \n-t \ttryb k (kompresja) lub d (dekompresja)" << endl;
		return 0;
	}
	
	
	
	//KODOWANIE	
	if (mod == "k")
	{
		ifstream out(file_in, ios_base::binary);
		if (out)
		{
			vector<node> cojest;
			int tablica[256]{ 0 };
			countchar(out, tablica);
			przep(tablica, cojest);
			drzewo(cojest);
			
			vector<key>kl;
			rek(&cojest[0],"", kl);
			ofstream in(cod);
			if (in.is_open())
			{
				wypK(in, kl);
			}
			else
				cerr << "\nblad otwarcia pliku\n";
			ofstream wp(file_out);
			if (wp.is_open()) {
				koduj(out, wp, kl);
			}
			else
				cerr << "blad otwarcia pliku\n";
			

		}
		else
			cerr << "blad otwarcia pliku";
	}
	//DEKODOWANIE	
	else if (mod == "d")
	{
		ifstream od(file_in);
		if (od)
		{
			ifstream ke(cod);
			if (ke)
			{
				vector<klucz>key;
				przepklucz(ke, key);
				ofstream odkod(file_out);
				if (odkod)
				{
					odszyfr(od, odkod, key);
				}
				else
					cerr<<"blad otwrcia pliku\n";
			}
			else
				cerr << "blad otwarcia pliku\n";
		}
		else
			cerr << "blad otwarcia pliku\n";
		
	} 

	return 0;
}