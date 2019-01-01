#include <iostream>
using namespace std;

int main()
{
    int t, u = 1, n, P[100000], Q[100000];
    cin >> t;
    while (t--)
    {
        cin >> n;
        for (int i = 0; i < n; ++i)
            cin >> P[i];
        for (int i = 0; i < n; ++i)
            cin >> Q[i];

        int fuel = 0, s = 0;
        for (int i = 0; i < 2 * n; ++i)
        {
            fuel += P[i % n] - Q[i % n];
            if (fuel < 0)
                fuel = 0, s = i + 1;
            if (i == s + n)
                break;
        }
        cout << "Case " << u++ << ": ";
        if (s >= n) cout << "Not possible\n";
        else cout << "Possible from station " << s + 1 << '\n';
    }
}
