#include <iostream>
#include <vector>
using namespace std;

typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<vi> vvi;

int aug(int u, vvi& G, vi& M, vb& V)
{
    if (V[u])
        return 0;
    
    V[u] = true;
    for (int v : G[u])
    {
        if (M[v] == -1 || aug(M[v], G, M, V))
        {
            M[v] = u;
            return 1;
        }
    }
    return 0;
}

int main()
{
    int T, b, n, w;
    ios::sync_with_stdio(false);
    cin >> T;
    for (int c = 0; c < T; ++c)
    {
        cin >> b >> n;
        vvi G(b);
        for (int i = 0; i < b; ++i)
            for (int j = 0; j < n; ++j)
                if (cin >> w, w)
                    G[i].push_back(j);

        int MCBM = 0;
        vi M(n, -1);
        for (int i = 0; i < b; ++i)
        {
            vb V(b, false);
            MCBM += aug(i, G, M, V);
        }
        cout << "Case " << c + 1 << ": ";
        cout << "a maximum of " << MCBM << " nuts and bolts ";
        cout << "can be fitted together\n";
    }
}
