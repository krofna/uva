#include <iostream>
using namespace std;

int main()
{
    int t, n, l;
    cin >> t;
    for (int k = 1; k <= t; ++k)
    {
        cin >> n;
        int m = 0, j = 0;
        for (int i = 0; i < n; ++i)
        {
            cin >> l;
            m += ((l / 30) + 1) * 10;
            j += ((l / 60) + 1) * 15;
        }
        cout << "Case " << k << ": ";
        if (m <= j)
            cout << "Mile ";
        if (j <= m)
            cout << "Juice ";
        cout << min(m, j) << '\n';
    }
}
