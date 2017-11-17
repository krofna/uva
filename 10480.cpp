#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

int n, m, a, b, w, s = 0, t = 1, R[50][50], P[50], S[50];

bool bfs(vvi& G, int r)
{
    queue<int> Q;
    Q.push(s);
    memset(P, -1, sizeof(P));
    while (!Q.empty())
    {
        int k = Q.front(); Q.pop();
        if (k == t)
            return true;

        if (r == 1)
            S[k] = true;
        
        for (int x : G[k])
        {
            if (P[x] == -1 && R[k][x] > 0)
                P[x] = k, Q.push(x);
            else if (r == 2 && !S[x] && R[k][x] == 0)
                cout << k + 1 << " " << x + 1 << '\n', R[k][x] = -1;
        }
    }
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    while (cin >> n >> m, n || m)
    {
        vvi G(n);
        memset(R, 0, sizeof(R));
        memset(S, 0, sizeof(S));
        for (int i = 0; i < m; ++i)
        {
            cin >> a >> b >> w;
            a -= 1; b -= 1;
            G[a].push_back(b);
            G[b].push_back(a);
            R[a][b] += w;
            R[b][a] += w;
        }
        int flow = 0;
        while (bfs(G, 0))
        {
            int aug = 1000;
            for (int x = t; x != s; x = P[x])
                aug = min(aug, R[P[x]][x]);
            
            for (int x = t; x != s; x = P[x])
                R[P[x]][x] -= aug, R[x][P[x]] += aug;
            
            flow += aug;
        }
        bfs(G, 1);
        bfs(G, 2);
        cout << '\n';
    }
}
