#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

typedef vector<int> vi;

int main()
{
    ios::sync_with_stdio(false);
    int n, m, x, G[20][20], a, b, t = 1;
    while (cin >> m)
    {
        for (int i = 0; i < 20; ++i)
            for (int j = 0; j < 20; ++j)
                G[i][j] = (i == j ? 0 : 20);

        for (int i = 0; i < 19; ++i)
        {
            if (i) cin >> m;
            for (int j = 0; j < m; ++j)
            {
                cin >> x; x -= 1;
                G[i][x] = 1;
                G[x][i] = 1;
            }
        }

        for (int k = 0; k < 20; ++k)
            for (int i = 0; i < 20; ++i)
                for (int j = 0; j < 20; ++j)
                    G[i][j] = min(G[i][j], G[i][k] + G[k][j]);
    
        cin >> n;
        cout << "Test Set #" << t++ << "\n";
        for (int i = 0; i < n; ++i)
        {
            cin >> a >> b;
            cout << setfill(' ') << setw(2) << a << " to ";
            cout << setfill(' ') << setw(2) << b << ": ";
            cout << G[a - 1][b - 1] << '\n';
        }
        cout << '\n';
    }
}
