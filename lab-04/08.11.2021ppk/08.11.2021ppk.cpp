
#include <iostream>
#include <iomanip>
#include <vector>
#include <cstdlib>

using namespace std;

void tablica()
{
    const int n = 10;
    int tab[n];
    srand(time(NULL));
    cout << "Tablica : ";
    for (int i = 0; i < n; i++)
    {
        tab[i] = rand() % 100;
        cout << tab[i] << " ";
    }
    cout << endl;

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

    cout << "Posortowana tablica : ";
    for (int i = 0; i < n; i++)
    {
        cout << tab[i] << " ";
    }

}
void binarna()
{
    int liczba;
    vector<int> bin;
    cout << "Podaj liczbe : ";
    cin >> liczba;
    while (liczba > 0)
    {
        bin.push_back(liczba % 2);
        liczba = liczba / 2;
    }
    for (int i = bin.size()-1; i >= 0; i--)
    {
        cout << bin[i]<<" ";
    }
}

void tabliczka()
{
    const int N = 16;
    int tab[N][N];
    cout << "   |";
    for (int i = 1; i <= N; i++)
    {
        cout.width(4);
        cout << i;
    }
    cout << endl;
    cout << "--------------------------------------------------------------------" << endl;
    for (int i = 0; i < N; i++)
    {
        cout.width(3);
        cout << i + 1<<"|";
        for (int j = 0; j < N; j++)
        {
            tab[i][j] = (i + 1) * (j + 1);
            cout.width(4);
            cout << hex << tab[i][j];
        }
        cout << endl;
    }
}

int main()
{
    tablica();
    //binarna();
   //tabliczka();
}