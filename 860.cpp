#include <iostream>
#include <sstream>
#include <map>
#include <cmath>
#include <iomanip>
using namespace std;

map<string, int> F;
int l = 0;

string clear(string& z)
{
    string r;
    for (char c : z)
        if (!ispunct(c))
            r += tolower(c);
    return r;
}

void add(string& s)
{
    istringstream iss(s);
    string z;
    while (iss >> z)
        F[clear(z)]++, ++l;
}

float ent()
{
    float s = 0;
    for (auto& p : F)
        s += p.second * (log10(l) - log10(p.second));
    return s / l;
}

int main()
{
    string s;
    while (getline(cin, s), s != "****END_OF_INPUT****")
    {
        l = 0;
        F.clear();
        add(s);
        while (getline(cin, s), s != "****END_OF_TEXT****")
            add(s);

        float e = ent();
        cout << l << ' ' << setprecision(1) << fixed << e << ' ';
        cout << setprecision(0) << e * 100. / log10(l) << '\n';
    }
}
