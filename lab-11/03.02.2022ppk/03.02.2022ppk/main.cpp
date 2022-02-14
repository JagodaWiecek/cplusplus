#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <fstream>

using namespace std;

string trim(const std::string& s)
{
	// "(Hamlet?"  --> "Hamlet"

	std::size_t first = s.find_first_not_of("(){}[]?!\'\"-.,;:*");
	std::size_t last = s.find_last_not_of("(){}[]?!\'\"-.,;:*");

	if (first != std::string::npos and last != std::string::npos)
		return s.substr(first, last - first + 1);
	else
		return std::string("");

}

int main()
{
	int tab[6] = { 55, 32, 11, 55, 11, 11 };
	vector<int> liczby;
	list <int> list1;
	list <int> list2;
	set<int> s;

	for(int i = 0; i < 6; i++)
	{
		liczby.push_back(tab[i]);
		list1.push_back(tab[i]);
		list2.push_front(tab[i]);
		s.insert(tab[i]);
	}
	 
	for (const int i : liczby)
	{
		cout << i << "\t";
	}
	cout << endl;

	for (const int i : list1)
	{
		cout << i << "\t";
	}
	cout << endl;

	for (const int i : list2)
	{
		cout << i << "\t";
	}
	cout << endl;
	for (const int i : s)
	{
		cout << i << "\t";
	}
	cout << endl;

	list<int>::iterator it = list1.begin();
	advance(it, 3);
	list1.insert(it, 22);
	for (const int i : list1)
	{
		cout << i << "\t";
	}
	cout << endl;
	//-----------------------------------------------------
	cout << "-----------------------------------------------------" << endl;
	map<string, string> ktoGdzie;
	//{te¿ dzia³a) ktoGdzie.insert({"imie","miasto"});
	
	ktoGdzie["Wladyslaw"] = "Krakow";
	ktoGdzie["Ala"] = "Wroclaw";
	ktoGdzie["Michal"] = "Warszawa";
	ktoGdzie["Rozalia"] = "Kielce";
	cout << "oni mieszkaja: \n";

	for (auto el : ktoGdzie)
	{
		cout << el.first << "\t" << el.second << endl;

	}
	cout << "-----------------------------------------------------" << endl;
	ofstream out("plik.txt");
	if (out.is_open())
	{
		out << "Ala ma kota, Ala ma psa. Ala ma kota i psa";
		out.close();
	}
	else
		cout << "problem z plikiem";
	ifstream in("plik.txt");
	if (!in.is_open())
	{
		cout << "problem z plikiem";
	}

	map<string, int> licznikSlow;
	string wyraz;
	while (in >> wyraz)
	{
		cout << trim(wyraz) << endl;
		licznikSlow[trim(wyraz)]++;
	}

	for (auto el : licznikSlow)
	{
		cout << el.first << "\t" << el.second << endl;
	}
	
}