#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<bool> vb;

int n, m, l, X1[100], Y1[100], X2[100], Y2[100];

float d1(int u, int v)
{
    return hypot(X1[u] - X2[v], Y1[u] - Y2[v]);
}

float d2(int u, int v)
{
    return hypot(X1[u] - X1[v], Y1[u] - Y1[v]);
}

bool c(int u, int v)
{
    return d1(u, v) + d1(u + 1, v) <= d2(u, u + 1) * 2.;
}

int aug(int u, vvi& G, vi& M, vi& N, vb& V)
{
    if (V[u])
        return 0;

    V[u] = true;
    for (int v : G[u])
    {
        if (M[v] == -1 || aug(M[v], G, M, N, V))
        {
            M[v] = u;
            N[u] = v;
            return 1;
        }
    }
    return 0;
}

int main()
{
    cin >> l;
    while (l--)
    {
        cin >> n >> m;
        for (int i = 0; i < n; ++i)
            cin >> X1[i] >> Y1[i];

        vvi G(n);
        for (int i = 0; i < m; ++i)
        {
            cin >> X2[i] >> Y2[i];
            for (int j = 0; j < n - 1; ++j)
                if (c(j, i))
                    G[j].push_back(i);
        }

        int MCBM = 0;
        vi M(m, -1), N(n, -1);
        for (int i = 0; i < n; ++i)
        {
            vb V(n, false);
            MCBM += aug(i, G, M, N, V);
        }

        cout << MCBM + n << '\n';
        for (int i = 0; i < n; ++i)
        {
            if (i) cout << " ";
            cout << X1[i] << " " << Y1[i];
            if (N[i] != -1) cout << " " << X2[N[i]] << " " << Y2[N[i]];
        }
        cout << '\n';
        if (l) cout << '\n';
    }
}
