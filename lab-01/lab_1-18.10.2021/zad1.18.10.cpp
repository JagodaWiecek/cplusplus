#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;
int main()
{
	/*Zadanie 1
	double a, b; //liczby zmienno przecinkowe
	cin >> a;
	cout << endl;
	cin >> b;
	cout << a << " + " << b << " = " << a + b <<endl;
	cout << a << " + " << b << " = " << a - b << endl;
	cout << a << " * " << b << " = " << a * b << endl;
	cout << a << " / " << b << " = " << a / b << endl;*/

	//Zadanie 2
	/*int wiek, wzrost;
	cout << " ile masz lat? : ";
	cin >> wiek;
	cout << endl;
	if (wiek < 18)
	{
		cout << "jestes niepelnoletni" << endl;
	}
	if (wiek == 18)
	{
		cout << "jestes pelnoletni" << endl;
	}
	if (wiek > 18 && wiek < 35)
	{
		cout << "jestes mlodym doroslym" << endl;
	}
	if (wiek >=35 && wiek <= 55)
	{
		cout << "jestes dorosly" << endl;
	}
	if (wiek > 55 && wiek < 80)
	{
		cout << "jestes stary" << endl;
	}
	if (wiek < 0)
	{
		cout << "nie zartoj sobie" << endl;
		cin >> wiek;
	}
	if (wiek >= 80 && wiek < 110)
		cout << "jestes ekstremalnie stary" << endl;
	if (wiek>110)
	{
		cout << "nie zartoj sobie" << endl;
		cin >> wiek;
	}*/
	int k;
	char odp;
	
	cout<< "czy twoja liczba jest mniejsza lub rowna 4?" << endl;
	cin >> odp;
	if (odp=='t')
	{
		cout << "Czy twoja liczba jest miejsza lub rowna 2?" << endl;
		cin >> odp;
		if (odp ='t')
		{
			cout << "czy woja liczba jest rowna 2?" << endl;
			if (odp=='n')
				cout << "Twoja liczba to 1!";
			if (odp=='t')
				cout << "Twoja liczba to 2!";
		}
		if (odp =='n')
		{
			cout << "Czy twoja liczba to 4?" << endl;
			cin >> odp;
			if (odp == 't')
				cout << "Twoja liczba to 4!" << endl;
			else
				cout << "Twoja liczba to 3!" << endl;
		}
	}
	if (odp == n)
	{

	}
	else
		cout << "to nie odpowiedz" << endl;

	/*
	cout << endl;
	if (liczba == 1)
		cout << "Masz 1!!" << endl;
	if (liczba == 2)
		cout << "Masz 2!!" << endl;
	if (liczba ==3)
		cout << "Masz 3!!" << endl;
	if (liczba ==4)
		cout << "Masz 4!!" << endl;
	if (liczba == 5)
		cout << "Masz 5!!" << endl; 
	if (liczba ==6 )
		cout << "Masz 6!!" << endl;
	if (liczba ==7)
		cout << "Masz 7!!" << endl;
	if (liczba == 8)
		cout << "Masz 8!!" << endl;*/

	return 0;
}