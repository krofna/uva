#include <iostream>
#include <cmath>
using namespace std;

typedef long long ll;

int main()
{
    ll t, n;
    cin >> t;
    while (t--)
    {
        cin >> n;
        cout << ll((sqrt(1 + 8 * n) - 1) / 2) << '\n';
    }
}
