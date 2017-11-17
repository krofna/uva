#include <iostream>
using namespace std;

string h(unsigned p)
{
    string s;
    while (p) s += '0' + p % 10, p /= 10;
    return s;
}

bool g(unsigned p)
{
    string s = h(p);
    return equal(s.begin(), s.begin() + s.size() / 2, s.rbegin());
}

unsigned f(unsigned p)
{
    return p + atoi(h(p).c_str());
}

int main()
{
    unsigned n, p;
    cin >> n;
    while (n--)
    {
        cin >> p;
        int iter = 1;
        while (!g(p = f(p))) ++iter;
        cout << iter << ' ' << p << '\n';
    }
}
