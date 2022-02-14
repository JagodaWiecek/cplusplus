#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

int fun(int a, int b)
{
	return a + b;
}

double zmienne(double z[],int n)
{
	
	for (int i = 0; i < n; i++)
	{
		cout << "Wprowadz " << i + 1 << " liczbe: ";

		cin >> z[i];
	}
	cout << endl;
	double max=z[0];
	for (int i = 1; i < n; i++)
	{
		if (max < z[i])
		{
			max = z[i];
		}
	}
	cout << "Najwieksza liczba to :";
	return max;
}
void my_swap(int &a, int &b)
{
	int pom;
	pom = a;
	a = b;
	b = pom;
	//cout << "a = " << a << "\t b = " << b;
}

void print_tab(int tab[], const int n)
{
	
	/*for (int i = 0; i < n; i++)
	{
		int pom;
		//cout << "Podaj liczbe numer " << i + 1 << ": ";
		cin >> pom;
		tab[i] = pom;
	}*/
	
	for (int i = 0; i < n; i++)
	{
		cout << tab[i] << " ";
	}
	cout << endl;
}
void sort_tab(int tab[],const int n)
{
	int index, min;

	for (int i = 0; i < n; i++)
	{
		index = i;
		for (int j = i + 1; j < n; j++)
		{
			if (tab[j] < tab[index])
			{
				index = j;
			}
		}
		min = tab[index];
		tab[index] = tab[i];
		tab[i] = min;
	}
}
bool pierwsza(int liczba)
{
	int ilosc = 0;
	
	for (int i = 1; i <= liczba; i++)
	{
		if (liczba % i == 0)
		{
			ilosc++;
		}

	}
	if (ilosc <= 2)
	{
		return true;
	}
	else return false;

}
void print_vec(const vector<int>&v)
{
	/*for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << " ";
	}*/
	for (auto a : v) cout << a<<" ";
	cout << endl;
}
void wypelnij( vector<int>&v,const int n)
{
	srand(time(NULL));
	for (int i = 0; i < n; i++)
	{
		v.push_back(rand() % 100);
	}
}void nadpisz_vec( vector<int>& v)
{
	for (auto &a : v) a = 7;
	
}

int main()
{
	//cout << fun(4, 6);

	/*double tab[5];
	cout<<zmienne(tab,5);*/

	/*int x = 6, y = 8;
	cout << "x = " << x << "\t y = " << y << endl;;
	my_swap(x, y);
	cout << "x = " << x << "\t y = " << y;*/

	/*const int a = 6;
	int tablica[a] = {4,5,1,8,0,0};
	int tab[2 * a] = { 7,7,7,7,7,7,7,7,7,7,7,6 };
	
	print_tab(tablica, a);
	sort_tab(tablica, a);
	print_tab(tablica, a);

	print_tab(tab, 2 * a); 
	sort_tab(tab, 2*a);
	print_tab(tab, 2 * a);*/

	//cout<<pierwsza(17);

	vector<int> tab = { 7, 5, 16, 8 };
	print_vec(tab);
	nadpisz_vec(tab);
	print_vec(tab);

	const int n = 6;
	vector<int>t;
	wypelnij(t,n);
	print_vec(t);

}
