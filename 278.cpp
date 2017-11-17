#include <iostream>
using namespace std;

int t, m, n;
char c;

int main()
{
    cin >> t;
    while (t--)
    {
        cin >> c >> m >> n;
        switch (c)
        {
        case 'K': cout << ((m + 1) / 2) * ((n + 1) / 2) << '\n'; break;
        case 'r': cout << min(m, n) << '\n'; break;
        case 'Q': cout << (min(n, m) <= 3 ? min(n, m) - 1 : min(n, m)) << '\n'; break;
        case 'k': cout << (m * n + 1) / 2 << '\n'; break;
        }
    }
}
