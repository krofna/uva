// todo linear time algoritam koji smo u vlaku smislili
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

int dfs(vvi& G, vi& V, int u)
{
    if (V[u])
        return 0;

    int sum = 1;
    for (int v : G[u])
        sum += dfs(G, V, v);
    return V[u] = sum;
}

int main()
{
    int n, t, x;
    while (cin >> n, n)
    {
        vvi G(n);
        for (int i = 0; i < n; ++i)
        {
            cin >> t;
            for (int j = 0; j < t; ++j)
            {
                cin >> x;
                G[i].push_back(x - 1);
            }
        }
        int m = 0, j = 0;
        for (int i = 0; i < n; ++i)
        {
            vi V(n, 0);
            int nm = dfs(G, V, i);
            if (nm > m)
                m = nm, j = i;
        }
        cout << j + 1 << '\n';
    }
}
