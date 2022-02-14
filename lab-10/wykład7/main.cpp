/** @file */

/*
   PODSTAWY PROGRAMOWANIA KOMPUTERÓW

   wykład 7: strumienie, struktury
 */

#define debug(x)  std::cerr << "(" << __LINE__ << ") " << #x << " == " << (x) << std::endl

#include <iostream>  // input-output stream
#include <fstream>   // file stream
#include <sstream>   // string stream 
#include <iomanip>   // manipulatory strumieni
#include <vector>
#include <cmath>

#include "funkcje.h"
#include "struktury.h"

int main (int ile, char * params[])
{

	// OPERACJE WEJŚCIA-WYJŚCIA


	// przykład bardziej skomplikowany: zapis macierzy

	const std::string NAZWA_PLIKU ("macierz");
	const int LICZBA_KOLUMN { 5};
	const int LICZBA_WIERSZY { 10 };
	zapisz_macierz(NAZWA_PLIKU, LICZBA_KOLUMN, LICZBA_WIERSZY);

	// przyklad bardziej skomplikowany: odczyt macierzy

	std::vector<std::vector<double>> wczytana_macierz = odczytaj_macierz (NAZWA_PLIKU);
	//  std::vector<std::vector<double>>  odczytaj_macierz  (const std::string & NAZWA_PLIKU);

	for (const std::vector<double> & wiersz : wczytana_macierz)
	{
		for (const double liczba : wiersz)
			std::cout << liczba << " ";
		std::cout << std::endl;
	}

	//     return 0;

	// MANIPULATORY   

	// setw -- szerokość pola
	std::cout << "------------------------" << std::endl;
	int n { 123 };
	for (int i = 0; i < 15; i++)
		std::cout << '[' << std::setw(i)  << n << ']' << std::endl;


	// setfill(char) 

	for (int i = 0; i < 15; i++)
		std::cout << '[' << std::setfill ('*') << std::setw(i)  << n << ']' << std::endl;

	std::cout << '[' << std::setfill (' ') << std::setw(0)  << n << ']' << std::endl;




	std::cout << "------------------------" << std::endl;
	double zmp { 3.1415926 };

	zmp = sqrt (zmp);

	std::cout << zmp << std::endl;


	// std::setprecision 
	for (int i = 0; i < 45; i++)
		std::cout << std::setprecision(i) << zmp << std::endl;


	// std::showpoint 
	zmp = 12;
	std::cout << std::defaultfloat << zmp << std::endl;
	std::cout << std::showpoint << zmp << std::endl;

	std::cout.unsetf(std::ios::showpoint);
	std::cout << zmp << std::endl;


	std::cout << "------------------------" << std::endl;

	// std::left, std::right 

	for (int i = 0; i < 15; i++)
		std::cout << '[' << std::setw(i) << std::left  << n << ']' << std::endl;

	// std::showpos    (show positive)
	for (int i = 0; i < 15; i++)
		std::cout << '[' << std::setw(i) << std::left << std::showpos << n << ']' << std::endl;


	// std::internal 
	for (int i = 0; i < 15; i++)
		std::cout << '[' << std::setw(i) << std::internal << std::showpos << n << ']' << std::endl;

	std::cout << "------------------------" << std::endl;
	zmp = 12.34;
	std::cout << std::setprecision(6) << zmp << std::endl;
	for (int i = 0; i < 15; i++)
	{   
		zmp *= 10;
		std::cout << zmp << std::endl;
	}

	// std::scientific
	std::cout << "------------------------" << std::endl;
	zmp = 0.01234;
	//std::cout << std::setprecision(6) << zmp << std::endl;
	for (int i = 0; i < 15; i++)
	{   
		zmp *= 10;
		std::cout << std::scientific << zmp << std::endl;
	}

	// std::fixed   

	std::cout << "------------------------" << std::endl;
	zmp = 0.01234;
	for (int i = 0; i < 15; i++)
	{   
		zmp *= 10;
		std::cout << std::fixed << zmp << std::endl;
	}


	// std::hexfloat  
	std::cout << "------------------------" << std::endl;
	zmp = 0.01234;
	for (int i = 0; i < 15; i++)
	{   
		zmp *= 16;
		std::cout << std::hexfloat << zmp << std::endl;
	}


	// std::defaultfloat 


	// std::fixed, std::scientific, std::hexfloat, std::defaultfloat

	// uzycie manipulatorów std::defaultfloat, std::scientific, std::hexfloat, std::fixed nie zmienia wartosci prezycji (precision)

	n = 1234;
	std::cout << "------------------------" << std::endl;
	std::cout << n << std::endl; 
	std::cout << std::oct << n << std::endl; 
	std::cout << std::hex << std::uppercase << n << std::endl; 
	std::cout << std::hex << std::nouppercase << n << std::endl; 
	std::cout << std::hex << n << std::endl; 
	std::cout << std::dec << n << std::endl; 

	// std::dec, std::oct, std::hex (std::nouppercase, std::uppercase) 


	std::cout.unsetf (std::ios_base::showpos);  // wyłącz flagę 
	std::cout << n << std::endl; 

	std::cout << "------------------------" << std::endl;

	// std::boolalpha 
	bool q { true };
	std::cout << q << std::endl;
	std::cout << not q << std::endl;

	std::cout << std::boolalpha << q << std::endl;
	std::cout << std::boolalpha << not q << std::endl;



	// FLAGI BLEDOW     
	/*  

	    flaga    | przyczyna             | good() | eof() | fail() | bad()
	    ---------+-----------------------+ -------+-------+--------+--------
	    goodbit  | brak błędów           | true   | false | false  | false 
	    eofbit   | koniec strumienia     | false  | true  | false  | false
	    failbit  | błąd logiczny         | false  | false | true   | false
	    badbit   | błąd odczytu / zapisu | false  | false | true   | true 

	 */

	{ 
		std::stringstream s;
		std::string napis {"Szumia jodly na gor szczycie."};
		debug(napis);

		s << napis;

		double liczba;

		s >> liczba;

		debug(s.rdstate());  
		debug(s.bad());      
		debug(s.eof());
		debug(s.fail());     
		debug(s.good());
		s.clear();   // zresowanie flag strumienia        

		// 		return 0;
		std::cout << std::endl;

		debug(s.rdstate());  
		debug(s.bad());      
		debug(s.eof());
		debug(s.fail());     
		debug(s.good());
		s.clear();   // zresowanie flag strumienia        

		std::cout << std::endl;

		char c;
		s >> c;   // 'S'
		debug(c);
		debug(s.rdstate());  
		debug(s.bad());      
		debug(s.eof());
		debug(s.fail());     
		debug(s.good());
		s.clear();   // zresowanie flag strumienia  

		// 		return 0;
		std::cout << std::endl;
		while (s >> c)
			;

		debug(s.rdstate());  // 6
		debug(s.bad());      // false
		debug(s.eof());      // true
		debug(s.fail());     // true
		debug(s.good());     // false
		s.clear();

		// 		return 0;
		std::cout << std::endl;

		std::ifstream p ("nie-istniejacy-plik");
		debug(p.rdstate());  // 4
		debug(p.bad());      
		debug(p.eof());
		debug(p.fail());     // true
		debug(p.good());     


		// 		return 0;
		std::cout << std::endl;
		p.open("main.cpp");  
		debug(p.rdstate());  
		debug(p.bad());      
		debug(p.eof());
		debug(p.fail());     
		debug(p.good()); 

		p.close();
	}   


	// STRUKTURY 

	// definiowane struktur

	// osoba z imieniem, nazwiskiem  i wiekiem     
	struct osoba 
	{
		std::string imie, nazwisko;   // pola, atrybuty
		int wiek;
		double oceny[4];
	}   Ania  ;  // <-------  !!!!!!!!!!!!!!!!!!!!!
	// typ  zmienna
	osoba   Janek;

	// dostęp do składowych
	Janek.imie = "Jan";
	Janek.nazwisko = "Kowalski";
	Janek.wiek = 21;

	Ania.imie = "Anna";
	Ania.nazwisko = "Nowak";
	Ania.wiek = 19;

	//     std::cout << Janek << std::endl; // 

	// inicjowanie struktur
	osoba Basia { "Barbara", "Jaworek", 20, { 4.5, 5.0, 3.5, 4.0} };

	std::cout << std::defaultfloat;
	std::cout << Basia.imie << " " << Basia.nazwisko << ", " << Basia.wiek << " ";

	std::cout << "[ ";
	for (int i = 0; i < 4; i++)
		std::cout << Basia.oceny[i] << " ";
	std::cout << "]" << std::endl;

	int abc {12};

	// rozmiar struktury  (sizeof)
	std::cout << sizeof(osoba) << std::endl;
	std::cout << 2 * sizeof(std::string) +  sizeof(int) + 4 * sizeof(double) << std::endl;

	// tablica struktur 

	osoba grupa[3] = { Janek, Ania, Basia };

	for (int i = 0; i < 3; i++)
		std::cout << grupa[i].imie << std::endl;


	// wektor struktur 

	std::vector<osoba> sekcja  { Janek, Ania, Basia };
	for (int i = 0; i < sekcja.size(); i++)
		std::cout << sekcja[i].nazwisko << std::endl;



	// struktura anonimowa
	struct 
	{
		int n;
		double d; 
		char c;
	}  trojka; 

	trojka.n = 234;

	// UNIE
	// deklaracja

	union moja_unia 
	{
		int n;
		double d; 
		char c;
	} krotka; 

	// dostęp

	krotka.c = 'a';
	std::cout << krotka.n << std::endl;
	std::cout << krotka.d << std::endl;

	// rozmiar unii 

	std::cout << sizeof(moja_unia) << std::endl;
	std::cout << sizeof(int) + sizeof(double) + sizeof(char) << std::endl;

	// rozmiar 


	//      union test
	//      {
	//          std::string napis;  // w unii nie może być string 
	//          double liczba;
	//      } t;

	// zagnieżdżone struktury:

	samochod wisla;

	wisla._nadwozie._nosnosc = nosnosc::samonosne;
	wisla._nadwozie.liczba_bryl = 3;
	wisla._nadwozie.liczba_drzwi = 5;
	wisla._podwozie.szerokosc = 200;
	wisla._podwozie.srednica = 780;
	wisla._silnik.numer_seryjny = "VBP34345NDSIE9934DD";
	wisla._silnik.moc = 35.4; 
	wisla._silnik._paliwo = paliwo::wodor;

	samochod odra { 
		{"3434LJ34LJ34L534", 56.6, paliwo::metan},   // silnik 
			{170, 670},                                  // podwozie
			{3, 2, nosnosc::ramowe}                      // nadwozie 
	};



	return 0;
} 

// Viva vox docet.
