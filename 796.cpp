#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<vi> vvi;

vvi G;
vii Q;
int c;

void dfs(vi& N, vi& L, int p, int u)
{
    L[u] = N[u] = c++;
    for (int v : G[u])
    {
        if (N[v] == -1)
        {
            dfs(N, L, u, v);
            L[u] = min(L[u], L[v]);
            if (L[v] == N[v])
                Q.push_back(minmax(u, v));
        }
        else if (v != p)
            L[u] = min(L[u], N[v]);
    }
}

int main()
{
    int n, a, b;
    while (cin >> n)
    {
        G.resize(n, vi());
        for (int i = 0; i < n; ++i)
        {
            string s;
            cin >> a >> s;
            int m = stoi(s.substr(1, s.size() - 2));
            G[a].resize(m);
            for (int j = 0; j < m; ++j)
            {
                cin >> b;
                G[a][j] = b;
            }
        }
        vi L(n, -1), N(n, -1);
        c = 0;
        for (int i = 0; i < n; ++i)
            if (N[i] == -1)
                dfs(N, L, i, i);
        
        cout << Q.size() << " critical links\n";
        sort(Q.begin(), Q.end());
        for (ii p : Q)
            cout << p.first << " - " << p.second << '\n';
        Q.clear();
        cout << '\n';
    }
}
