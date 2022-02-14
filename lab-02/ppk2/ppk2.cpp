
#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>

using namespace std;

void zad2()
{
    int liczba, ilosc = 0;
    cout << "podaj liczbe: ";
    cin >> liczba;
    for (int i = 1; i <= liczba; i++)
    {
        if (liczba % i == 0)
        {
            ilosc++;
        }

    }
    if (ilosc <= 2)
    {
        cout << "\nPodana liczba jest liczba pierwsza";
    }
    else cout << "\nPodana liczba nie jest liczba pierwsza ";
}
void zad3()
{

    // rand() -> liczba pseudolosowa od 0 d RAND_MAX
    int liczba = rand() % 100 + 1;  //liczba od 1 do 100

    //std::cout << "Zgadnij liczbe" << std::endl;
    int x = -1, zadana_liczba_prob = 10;
    int proba = 1;
    while (x != liczba && proba <= zadana_liczba_prob)
    {
        cout << "Zgadnij liczbe" << endl;
        cin >> x;

        proba++;
        if (x == liczba)
            cout << "Brawo" <<endl;
        else if (x < liczba)
            cout << "Moja liczba jest wieksza" << endl;
        else
            cout << "Moja liczba jest mniejsza" << endl;

    }
}

void zad5wcz()
{
    double a1, b1, c1, a2, b2, c2;
    double x, y, W, Wx, Wy;
    cin >> a1 >> b1 >> c1 >> a2 >> b2 >> c2;
    W = a1 * b2 - a2 * b1;
    Wx = c1 * b2 - c2 * b1;
    Wy = a1 * c2 - a2 * c1;
    x = Wx / W;
    y = Wy / W;

    if (W!=0)
    {
        cout << "Uklad oznaczony\n";
        cout << "W = " << W << ", Wx = " << Wx << ", Wy = " << Wy << ", x = " << x << ", y = " << y;
    }
    if (Wx == 0 && Wy == 0)
    {
        cout << "Uklad jest nieoznaczony";
    }
    if (W==0 && (Wx == 0 && Wy != 0) || (Wx != 0 && Wy == 0))
    {
        cout << "Uklad jest przeczny";
    }
}

void zad6wcz()
{
    int rok;
    double przebieg;
    cout << "Podaj rok w ktorym wybiles ostatnio przebieg: ";
    cin >> rok;
    cout << "Podaj jak duzo przejechales od ostatniego przebiegu(w km): ";
    cin >> przebieg;

    { 
        if (((2021 - rok) >= 2 && (2021 - rok) <= 3) || (przebieg >= 30000 && przebieg <= 36000))
    {
        cout << "Musisz wykonac diagnostyke samochodu";
    }
        else if (2021 - rok > 3 || przebieg > 36000)
    {
        cout << "PILNE -> Musisz wykonac diagnostyke samochodu";
    }
        else cout << "Wszystko w porzadku";

    }

    if (przebieg >= 40000 && przebieg<48000)
    {
        cout << "\nMusisz wymienic swiece w samochodzie";
    }
    else if (przebieg >= 48000)
    {
        cout << "\nPILNE -> Musisz wymienic swiece w samochodzie";
    }


    if (przebieg >= 90000 || 2021 - rok >= 5)
    {
        cout << "\nMusisz wymienić rozrzad";
    }
}

void zad4()
{
    int a,sr;
    double odch,razem=0,max,min,suma=0;
    char odp;
    vector<int> tabvec;
    cout << "Wprowadz liczbe: ";
    cin >> a;
    tabvec.push_back(a);
    max = tabvec[0];
    min = tabvec[0];
    cout << "Chcesz wpisac wiecej? wpisz t [tak] lub n [nie] : ";
    cin >> odp;
    while (odp == 't')
    {
        cout << "Wprowadz liczbe: ";
        cin >> a;
        tabvec.push_back(a);
        cout << "\nChcesz wpisac wiecej? wpisz t [tak] lub n [nie] : ";
        cin >> odp;
    }
    for (int i = 0; i < tabvec.size(); i++)
    {
        razem+= tabvec[i];
        if (tabvec[i] < min)
        {
            min = tabvec[i];
        }

        else if (tabvec[i] > max)
        {
            max = tabvec[i];
        }
    }
    sr = razem / tabvec.size();

    for (int j = 0; j < tabvec.size(); j++)
    {
        suma += pow((tabvec[j]-sr),2);
    }
    odch = (sqrt(suma)/tabvec.size());
    cout <<"W tablicy jest " << tabvec.size()<<" Liczb ";
    cout <<"Srednia arytmetyczna podanych liczb to: " << sr;
    cout << "\nmajwieksza wartosc tablicy to: " << max;
    cout << "\nnajmniejsza wartosc tablicy to: " << min;
    cout << "\nOdchylenie jest rowne: " << odch;
}


int main()
{
   // zad2();
   // zad3();
   //zad5wcz();
   // zad6wcz();
    zad4();
}
