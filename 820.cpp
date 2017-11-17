#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

int n, s, t, c, a, b, w, k, u = 1, P[100], R[100][100];

bool ap(vvi& G)
{
    queue<int> Q;
    Q.push(s);
    memset(P, -1, sizeof(P));
    while (!Q.empty())
    {
        k = Q.front(); Q.pop();
        if (k == t)
            return true;

        for (int x : G[k])
            if (P[x] == -1 && R[k][x] > 0)
                P[x] = k, Q.push(x);
    }
    return false;
}

int main()
{
    while (cin >> n, n)
    {
        vvi G(n);
        cin >> s >> t >> c;
        s -= 1; t -= 1;
        memset(R, 0, sizeof(R));
        for (int i = 0; i < c; ++i)
        {
            cin >> a >> b >> w;
            a -= 1; b -= 1;
            G[a].push_back(b);
            G[b].push_back(a);
            R[a][b] += w;
            R[b][a] += w;
        }
        int flow = 0;
        while (ap(G))
        {
            int aug = 1000;
            for (int x = t; x != s; x = P[x])
                aug = min(aug, R[P[x]][x]);
            
            for (int x = t; x != s; x = P[x])
                R[P[x]][x] -= aug, R[x][P[x]] += aug;
            
            flow += aug;
        }
        cout << "Network " << u++ << '\n';
        cout << "The bandwidth is " << flow << ".\n\n";
    }
}
