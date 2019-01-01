#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int t, G[100][100], N, R;
    cin >> t;
    for (int u = 1; u <= t; ++u)
    {
        cin >> N >> R;
        for (int i = 0; i < N; ++i)
            for (int j = 0; j < N; ++j)
                G[i][j] = (i == j? 0 : N);

        for (int i = 0; i < R; ++i)
        {
            int u, v;
            cin >> u >> v;
            G[u][v] = G[v][u] = 1;
        }
        for (int k = 0; k < N; ++k)
            for (int i = 0; i < N; ++i)
                for (int j = 0; j < N; ++j)
                    G[i][j] = min(G[i][j], G[i][k] + G[k][j]);

        int s, d;
        cin >> s >> d;
        int m = 0;
        for (int i = 0; i < N; ++i)
            m = max(m, G[s][i] + G[i][d]);
        cout << "Case " << u << ": " << m << '\n';
    }
}
