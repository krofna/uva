#include <iostream>
using namespace std;

int ipow(int b, int p, int m)
{
    if (!p)
        return 1;

    if (p % 2)
        return ((b % m) * (ipow(b, p - 1, m) % m)) % m;
    
    int nb = ipow(b, p / 2, m);
    return ((nb % m) * (nb % m)) % m;
}

int main()
{
    int b, p, m;
    while (cin >> b >> p >> m)
        cout << ipow(b, p, m) << '\n';
}
