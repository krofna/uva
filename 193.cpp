#include <iostream>
#include <vector>
using namespace std;

typedef vector<__int128> vi;

int c, best;
__int128 bc;

void dfs(vi& G, int i, __int128 s)
{
    if (i == G.size())
    {
        if (c > best)
        {
            bc = s;
            best = c;
        }
        return;
    }
    
    dfs(G, i + 1, s);
    s |= (__int128(1) << i);
    if (G[i] & s)
        return;

    c++;
    dfs(G, i + 1, s);
    c--;
}

int main()
{
    int m, n, k;
    cin >> m;
    while (cin >> n >> k)
    {
        vi G(n);
        int a, b;
        for (int i = 0; i < k; ++i)
        {
            cin >> a >> b; a--; b--;
            G[a] |= (__int128(1) << b);
            G[b] |= (__int128(1) << a);
        }
        c = best = bc = 0;
        dfs(G, 0, 0);
        cout << best << '\n';
        bool flg = false;
        for (int i = 0; i < n; ++i)
        {
            if (bc & (__int128(1) << i))
            {
                if (flg) cout << ' ';
                cout << i + 1;
                flg = true;
            }
        }
        cout << '\n';
    }
}
