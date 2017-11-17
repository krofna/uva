#include <iostream>
using namespace std;

int w(int n)
{
    int s = 0;
    for (int i = 1; i <= n; ++i)
        s += i * (i + 1) * (i + 2) / 2;
    return s;
}

int main()
{
    int t, n;
    cin >> t;
    for (int u = 1; u <= t; ++u)
    {
        cin >> n;
        cout << u << " " << n << " " << w(n) << '\n';
    }
}
