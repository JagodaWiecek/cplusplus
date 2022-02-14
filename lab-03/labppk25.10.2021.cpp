#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

void zadN()
{
    int n;
    cout << "Prosze podac liczbe: " <<endl;
    cin >> n;
    cout << endl;
    for (int i = 1; i <= n; i++)
    {
        cout << i << " ";
    }
    cout << endl;
    int i = 1;
    while (i <= n)
    {
        cout << i << " ";
        i++;
    }
    cout << endl;
    int d = 1;
    do
    {
        cout << d << " ";
        d++;
    } while (d <= n);
}

void zadN_1()
{
    int n;
    cout << "Prosze podac liczbe: " << endl;
    cin >> n;
    int d = n;
    cout << endl;
    for (int i = n; i>=1; i--)
    {
        cout << i << " ";
    }
    cout << endl;
    int i = 1;
    while (n >= 1)
    {
        cout << n << " ";
       n--;
    }
    cout << endl;

    do
    {
        cout << d << " ";
        d--;
    } while (d>=1);
}
void potega()
{
    int podstawa, wykladnik, mnozenie;
    cout << "podaj liczbe: ";
    cin >> podstawa;
    mnozenie = podstawa;
    cout << "podaj wartosc potegi: ";
    cin >> wykladnik;
    cout << podstawa << " ";
    for (int i = 1; i <= wykladnik; i++)
    {
        podstawa = podstawa * mnozenie;
        cout << podstawa << " ";
    }
}


void zad1_2()
{
    int pierwsza, ostatnia, dzielnik;
    cout << "podaj przedzial: \n";
    cout << "od: ";
    cin >> pierwsza;
    cout << "do: ";
    cin >> ostatnia;
    cout << "podaj dzielnik: ";
    cin >> dzielnik;
    while (pierwsza <= ostatnia)
    {
        if (pierwsza % dzielnik == 0)
            cout << pierwsza << " ";
        pierwsza++;
    }
}

int main()
{
   // zadN();
   //zadN_1();
    //zad1_2();
    //potega();
    srand(time(NULL));
    int liczba = rand() % 101;
    int x = -1;

    
    

}