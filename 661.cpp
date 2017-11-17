#include <iostream>
using namespace std;

int main()
{
    int n, m, c, k[20], l, t = 1;
    while (cin >> n >> m >> c, n || m || c)
    {
        for (int i = 0; i < n; ++i)
            cin >> k[i];

        bool S[20] = {};
        int h = 0, mx = 0;
        for (int i = 0; i < m; ++i)
        {
            cin >> l; l--;
            S[l] = !S[l];
            if (S[l])
                h += k[l];
            else
                h -= k[l];
            mx = max(mx, h);
        }
        cout << "Sequence " << t++ << '\n';
        if (mx <= c)
        {
            cout << "Fuse was not blown.\n";
            cout << "Maximal power consumption was " << mx << " amperes.\n\n";
        }
        else
            cout << "Fuse was blown.\n\n";
    }
}
