
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void wyp()
{
	const int n = 5;
	int tab[n] = {1,2,3,4,5};
	for (int i = 0; i < n; i++)
	{
		cout << *(tab + i) << ", ";
	}
	cout << endl;
}
void wyp1(int *tab,int const n)
{
	
	for (int i = 0; i < n; i++)
	{
		cout << *(tab + i) << ", ";
	}
	cout << endl;
}
double** tab1(int m, int n)
{

	double** tab2D = new double* [m];

	for (int i = 0; i < m; i++)
	{
		tab2D[i] = new double[n];
	}
	for (int j = 0; j < m; j++)
	{
		for (int k = 0; k < n; k++)
		{
			tab2D[j][k] = (double)rand() / RAND_MAX * 999;             //[0,999]
		}
	}
	return tab2D;
}
void wyp2(double ** tab, const int n,const int m)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << tab[i][j] << "\t";
		}
		cout << endl;
	}
}

int main()
{
	const int s = 6;
	int tab[s] = { 4,5,6,7,8,9 };
	const int a = 3, b = 5;
	//wyp();
	//wyp1(tab, s);
	//wyp2(tab1(a, b),a,b);


		
}

