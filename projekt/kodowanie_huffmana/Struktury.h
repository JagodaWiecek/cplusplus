/**file*/
#include <string>
#ifndef STRUKTURY_H	
#define STRUKTURY_H

/// Struktura do wyczytania znakow, ktore wystapily w pliku i zliczenia ich ilosci wystapien, oraz wskazniki "lewe", "prawe", potrzebne do stworzenia drzewa.
/// @param znak - znak pliku
/// @param licznik - zlicza ile razy dany znak wystapil 
/// @param lewe - wskaznik na lewa galaz
/// @param prawe - wskaznik na prawa galaz
struct node {
	
	int znak=NULL; 
	int licznik=0; 
	node* lewe = nullptr; 	
	node* prawe = nullptr; 
};

 /// struktura do stworzenia klucza do zakodowania
/// @param znak ktory pojawil sie w pliku
/// @param licznik - zlicza ile razy dany znak sie pojawil
/// @param kod - kod ktory powstal poprzez drzewo.
struct key {
	
	int znak; 
	int lw; 
	std:: string kod;
};
/// struktura do wyczytania klucza z pliku
/// @param z - znak, konkretna litera z ktora pojawila sie w tekscie
/// @param k - kod z slownika przypisany do konkretnej litery 
struct klucz {
	
	int z;	
	std::string k; 
};
#endif