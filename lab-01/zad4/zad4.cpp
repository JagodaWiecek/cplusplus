#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    double a, b, c;
    cin >> a;
    cin >> b;
    cin >> c;
    if (a == 0)
    {
        if (b == 0)
        {
            if (c == 0)
                cout << "Funkcja tozsamosciowa\n";
            else cout << "sprzecznosc\n";
        }
        else
        {
            cout << "wynik to: " << -c / b;
        }
    }
    else
        {
            double d = b * b - 4 * a * c;
            if (d > 0)
            {
                double x1 = (-b - sqrt(d)) /( 2 * a);
                double x2= (-b + sqrt(d)) / (2 * a);
                cout << "wyniki to: " << x1 << " " << x2 << '\n';
            }
            else if (d == 0)
            {
                double x = -b / (2 * a);
                cout << "wynik to: " << x << '\n';
            }
            else
            {
                cout << "brak rozwiazan";
            }
        }

    }