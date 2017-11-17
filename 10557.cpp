#include <iostream>
#include <vector>
#include <limits>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

int n, e, m, k;

bool dfs(vvi& G, vi& V, int u)
{
    V[u] = true;
    for (int v : G[u])
        if (!V[v])
            if (v == n - 1 || dfs(G, V, v))
                return true;
    return false;
}

bool dfs(vvi& G, int u)
{
    vi V(n, false);
    return dfs(G, V, u);
}

bool bf(vvi& G, vi& E)
{
    vi D(n, numeric_limits<int>::min());
    D[0] = 100;
    for (int i = 0; i < n - 1; ++i)
        for (int j = 0; j < n; ++j)
            for (int k : G[j])
                if (D[j] > 0)
                    D[k] = max(D[k], D[j] + E[k]);

    if (D[n - 1] > 0)
        return true;
    
    for (int j = 0; j < n; ++j)
        for (int k : G[j])
            if (D[j] > 0 && D[j] + E[k] > D[k])
                if (dfs(G, j))
                    return true;
    
    return false;
}

int main()
{
    while (cin >> n, n != -1)
    {
        vvi G(n);
        vi E(n);
        for (int i = 0; i < n; ++i)
        {
            cin >> e >> m;
            E[i] = e;
            for (int j = 0; j < m; ++j)
            {
                cin >> k;
                G[i].push_back(k - 1);
            }
        }
        if (bf(G, E))
            cout << "winnable\n";
        else
            cout << "hopeless\n";
    }
}
