#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <chrono>
#include <random>
#include <sstream>
#include <cstdlib>
#include <ctime>

using namespace std;

void num_gen(const string& out_name, int n);
unsigned long long GetFileSize(const string& file_name);

double los()
{
	static default_random_engine liczba(chrono::system_clock::now().time_since_epoch().count());
	normal_distribution<double> wzrost(0, 9999);

	return wzrost(liczba);
}
void num_gen(const string& out_name, int n)
{
	ofstream out(out_name);
	if (out)
	{
		for (int i = 1; i <= n; i++)
		{
			int l=los();
			 
			out << l;
			cout << "\t";
		}
		cout << endl;
	}
	else
	{
		cout << "plik nieotwarty";
		exit(1);
	}
	
}
unsigned long long GetFileSize(const string& file_name)
{
	int pozycja;
	ifstream in(file_name);
	if (in)
	{
		in.seekg(0, ios_base::end); //wskazanie gdzie ma byæ kursor
		pozycja = in.tellg(); //miejsce gdzie jest kursor
		return pozycja;
	}
	else
	{
		cout << "plik nieotwarty";
		return 0;
	}
}
void calculate_statistics(const string& intput_file_name, const string& output_file_name_txt, const string& output_file_name_bin)
{
	ifstream odczyt(intput_file_name);
	ofstream outn(output_file_name_txt);
	ofstream outb(output_file_name_bin);
	double x;
}
int main()
{
	ofstream zap ("moj_plik.txt");
	int x = 11;
	
	 num_gen("moj_plik.txt", x);
	 cout << GetFileSize("test.txt");
}