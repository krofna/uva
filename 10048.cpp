#include <iostream>
using namespace std;

int main()
{
    int c, s, q, D[100][100], c1, c2, d, u = 1;
    while (cin >> c >> s >> q, c || s || q)
    {
        for (int i = 0; i < c; ++i)
            for (int j = 0; j < c; ++j)
                D[i][j] = (i == j ? 0 : 1e9);

        for (int i = 0; i < s; ++i)
        {
            cin >> c1 >> c2 >> d;
            c1 -= 1, c2 -= 1;
            D[c1][c2] = D[c2][c1] = d;
        }
        for (int k = 0; k < c; ++k)
            for (int i = 0; i < c; ++i)
                for (int j = 0; j < c; ++j)
                    D[i][j] = min(D[i][j], max(D[i][k], D[k][j]));

        if (u != 1) cout << '\n';
        cout << "Case #" << u++ << '\n';
        for (int i = 0; i < q; ++i)
        {
            cin >> c1 >> c2;
            c1 -= 1, c2 -= 1;
            if (D[c1][c2] == 1e9)
                cout << "no path\n";
            else
                cout << D[c1][c2] << '\n';
        }
    }
}
