#include <iostream>
#include <random>  //std::default_random_engine, std::uniform_real_distribution
#include <cmath>

using namespace std;

struct punkt {
    double x, y;
};
struct kwadrat
{
    punkt a, b;

};

void poka_punkt(const punkt& a)
{
    cout << "{" << a.x << ", " << a.y << "}" << endl;
}
double od_punkt(punkt z,punkt c)
{
    double odl;
    odl = sqrt( (pow(double(c.x - z.x),2) + (pow (double(c.y - z.y),2))));
    return odl;
}
double kw(punkt z, punkt c)
{
    double odl, kwad;
    kwad = pow (double(sqrt((pow(double(c.x - z.x), 2) + (pow(double(c.y - z.y), 2))))),2);
    
    return kwad;
}

punkt sr_punkt(punkt z, punkt c)
{
    punkt d;
    d.x = (z.x + c.x) / 2;
    d.y = (z.y + c.y) / 2;
    return d;
}
double wiekszy(double kw, double kw2)
{
    double duzy;
    if (kw < kw2) duzy = kw2;
    else duzy = kw;
    return duzy;
}


int main() {

    punkt a = { 13.4, 3.2 };
    punkt b = a;

    poka_punkt(a);
    b.x = 1.1;
    poka_punkt(b);

    kwadrat k;
    k.a.x = 2;
    k.a.y = 3;

    k.b.x = 6;
    k.b.y = 7;

    
    // przyk³adowa generacja 10 liczb rzeczywistych z zakresu 0 do 100
    default_random_engine generator;
    uniform_real_distribution<double> distribution(0.0, 100.00);
    double num;
    for (int i = 0; i < 10; ++i) {
        num = distribution(generator);
        cout << num << " ";
    }
    cout << endl;
    cout<<od_punkt(a, b);
    cout << endl;
    poka_punkt(sr_punkt(a, b));
    cout << endl;
    cout << kw({ 2,3 }, { 5,7 });
    cout << endl;
    cout << wiekszy(kw({ 2,3 }, { 5,7 }), kw({ 1,2 }, { 6,1 }));
    return 0;
}