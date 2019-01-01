#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n, N = 'z' - 'a' + 1, inf = 1e9;
    while (cin >> n, n)
    {
        int G[N][N][2];
        for (int i = 0; i < N; ++i)
            for (int j = 0; j < N; ++j)
                for (int k = 0; k < 2; ++k)
                    G[i][j][k] = (i == j? 0 : inf);

        for (int i = 0; i < n; ++i)
        {
            char y, d, a, b;
            int e;
            cin >> y >> d >> a >> b >> e;
            int aa = a - 'A', bb = b - 'A';
            G[aa][bb][y == 'Y'] = min(G[aa][bb][y == 'Y'], e);
            if (d == 'B')
                G[bb][aa][y == 'Y'] = min(G[bb][aa][y == 'Y'], e);
        }

        for (int k = 0; k < N; ++k)
            for (int i = 0; i < N; ++i)
                for (int j = 0; j < N; ++j)
                    for (int l = 0; l < 2; ++l)
                        G[i][j][l] = min(G[i][j][l], G[i][k][l] + G[k][j][l]);

        char aa, bb;
        cin >> aa >> bb;
        int a = aa - 'A', b = bb - 'A', r = 1e9;
        for (int i = 0; i < N; ++i)
            r = min(r, G[a][i][1] + G[b][i][0]);
        if (r != 1e9)
        {
            cout << r;
            for (int i = 0; i < N; ++i)
                if (G[a][i][1] + G[b][i][0] == r)
                    cout << ' ' << char('A' + i);
            cout << '\n';
        }
        else
            cout << "You will never meet.\n";
    }
}
