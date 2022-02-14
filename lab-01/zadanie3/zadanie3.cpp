#include <iostream>

using namespace std;

int main()
{
	
	char odp;

	cout << "czy twoja liczba jest mniejsza lub rowna 4?" << endl;
	cin >> odp;
	if (odp == 't')
	{
		cout << "Czy twoja liczba jest miejsza lub rowna 2?" << endl;
		cin >> odp;
		if (odp == 't')
		{
			cout << "czy woja liczba jest rowna 2?" << endl;
			if (odp == 'n')
				cout << "Twoja liczba to 1!";
			if (odp == 't')
				cout << "Twoja liczba to 2!";
		}
		if (odp == 'n')
		{
			cout << "Czy twoja liczba to 4?" << endl;
			cin >> odp;
			if (odp == 't')
				cout << "Twoja liczba to 4!" << endl;
			else
				cout << "Twoja liczba to 3!" << endl;
		}
	}
	if (odp == 'n')
	{
		cout << "czy twoja liczba jest wieksza od 4 i mniejsza lub rowna 6?" << endl;
		cin >> odp;
		if (odp == 't')
		{
			cout << "czy twoja liczba to 5" << endl;
			cin >> odp;
			if (odp == 't')
				cout << "twoja liczba to 5!" << endl;
			else cout << "twoja liczna to 6" << endl;
		}
		if (odp == 'n')
		{
			cout << "czy twoja liczba to 8?" << endl;
			cin >> odp;
			if (odp == 't')
				cout << "twoja liczba to 8!" << endl;
			else cout << "twoja liczba to 7" << endl;
		}
	}
	else
		cout << "to nie odpowiedz" << endl;
	return 0;
}
