#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

const int MAX = 10000;

int R[202][202], s = 200, t = 201;
vvi G;
vi P;

bool AP()
{
    queue<int> Q;
    P.assign(G.size(), -1);
    Q.push(s);
    while (!Q.empty())
    {
        int k = Q.front(); Q.pop();
        if (k == t)
            return true;

        for (int x : G[k])
            if (P[x] == -1 && R[k][x] > 0)
                P[x] = k, Q.push(x);
    }
    return false;
}

void edge(int u, int v, int w)
{
    G[u].push_back(v);
    G[v].push_back(u);
    R[u][v] = w;
}

int main()
{
    int n, m;
    while (cin >> n)
    {
        memset(R, 0, sizeof(R));
        G.assign(202, vi());
        for (int i = 0; i < n; ++i)
        {
            int c;
            cin >> c;
            edge(i * 2, i * 2 + 1, c);
        }
        cin >> m;
        for (int i = 0; i < m; ++i)
        {
            int a, b, c;
            cin >> a >> b >> c;
            a--, b--;
            edge(a * 2 + 1, b * 2, c);
        }
        int b, d;
        cin >> b >> d;
        for (int i = 0; i < b; ++i)
        {
            int k;
            cin >> k, k--;
            edge(s, k * 2, 1e9);
        }
        for (int i = 0; i < d; ++i)
        {
            int k;
            cin >> k, k--;
            edge(k * 2 + 1, t, 1e9);
        }
        int MF = 0;
        while (AP())
        {
            int aug = 1e9;
            for (int x = t; x != s; x = P[x])
                aug = min(aug, R[P[x]][x]);

            for (int x = t; x != s; x = P[x])
                R[P[x]][x] -= aug, R[x][P[x]] += aug;

            MF += aug;
        }
        cout << MF << '\n';
    }
}
