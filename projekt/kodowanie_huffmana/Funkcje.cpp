/**file*/
#include <iostream>
#include <iomanip>
#include <vector>
#include <sstream>
#include <string>
#include <fstream>
#include <chrono>
#include <algorithm>

#include "Funkcje.h"
#include "Struktury.h"


using namespace std;

void countchar(ifstream& plik,int *tab)
{
	plik.seekg(0, plik.end);
	int d = plik.tellg();
	plik.seekg(0, plik.beg);

	char buf[1000];

	for (int k=0;k<(d/1000);k++)
	{
		plik.read(buf, 1000);
		for (int i = 0; i < 1000; i++)
		{
			tab[buf[i]]++;
		}
	}
	int licz = d - plik.gcount();
	plik.read(buf, licz);
	for (int i = 0; i < licz; i++)
	{
		tab[buf[i]]++;
	}

}

void przep(int* tab, vector<node>& vec)
{
	for (int i = 0; i < 256; i++)
	{
		if (tab[i] != 0)
		{
			node z;
			z.znak = i;
			z.licznik = tab[i];
			vec.push_back(z);
		}
	}
}

void drzewo(vector<node> &tab)
{
	while (tab.size() > 1)
	{
		node temp;
		temp.lewe=new node(tab[tab.size()-1]);
		temp.prawe=new node(tab[tab.size()-2]);
		temp.licznik = tab[tab.size() - 1].licznik+ tab[tab.size() - 2].licznik;
		tab.pop_back();
		tab.pop_back();
		tab.push_back(temp);
		sort(tab.begin(), tab.end(), [](const node& l, const node& p) {return l.licznik > p.licznik; });

	}
}

void rek(node *korz, string code, vector<key>&kod)
{
	if (korz->znak != NULL)
	{
		key temp;
		temp.znak=korz->znak;
		temp.kod=code;
		temp.lw=korz->licznik;
		kod.push_back(temp);
		return;
	}
	rek(korz->lewe, code + "0", kod);
	rek(korz->prawe, code + "1", kod);

	delete korz->lewe;
	delete korz->prawe;
	korz->lewe = nullptr;
	korz->prawe = nullptr;
	sort(kod.begin(), kod.end(), [](const key& lewy, const key& prawy) { return lewy.lw > prawy.lw; });
}

void wypK(ofstream &plik,vector<key>klucz)
{
	for (int i = 0; i < klucz.size(); i++)
	{
		plik  << klucz[i].znak << '\t' << klucz[i].kod << endl;
	}
	plik.close();
 }

void koduj(ifstream& plik,ofstream &in,vector<key> klucz)
{
	string tekst;
	plik.seekg(0, plik.beg);
	while (getline(plik, tekst))
	{
		
		for (int i = 0; i < tekst.length(); i++)
		{
			bool jest = false;
			for (int j = 0; j < klucz.size() && !jest; j++)
			{
				if (tekst[i] == (char)klucz[j].znak)
				{
					in << klucz[j].kod;
					jest = true;
				}
			}
		}
	}
	plik.close();
	in.close();
}

void przepklucz(ifstream& plik, vector<klucz> &k)
{
	int z;
	string kod;
	while (plik >> z >> kod)
	{
		klucz temp;
		temp.z = z;
		temp.k = kod;
		k.push_back(temp);
	}
	sort(k.begin(), k.end(), [](const klucz& l, const klucz& p) {return l.k.length() < p.k.length();});
	plik.close();
}

void odszyfr(ifstream& plik, ofstream& in, vector<klucz> k)
{
	plik.seekg(0, plik.beg);
	string tekst;
	vector<klucz> temp = k;
	while (getline(plik,tekst))
	{
		
		string str{};
		for (int i = 0; i < tekst.length(); i++)
		{
			str += tekst[i];
			bool jest = false;
			for (int j = 0; j < k.size() ; j++)
			{
				if (str == temp[j].k)
				{
					in << (char)k[j].z;
					str = {};
				}
			}
			
		}
	}
	plik.close();
	in.close();
	
}
