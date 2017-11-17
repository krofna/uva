#include <iostream>
using namespace std;

int main()
{
    unsigned n, m;
    cin >> n;
    while (n--)
    {
        cin >> m;
        int b1 = __builtin_popcount(m);
        unsigned mm = 0;
        for (unsigned i = 1; m; i <<= 4)
        {
            mm += i * (m % 10);
            m /= 10;
        }
        int b2 = __builtin_popcount(mm);
        cout << b1 << ' ' << b2 << '\n';
    }
}
