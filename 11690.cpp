#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <unordered_map>
using namespace std;

typedef vector<int> vi;

struct UF
{
    vi p, s, r;

    UF(int n) : p(n, 0), r(n, 0), s(n, 0)
    {
        iota(p.begin(), p.end(), 0);
    }

    int f(int i)
    {
        return (p[i] == i) ? i : (p[i] = f(p[i]));
    }

    void h(int x, int y)
    {
        p[y] = x;
        s[x] += s[y];
    }

    void u(int i, int j)
    {
        int x = f(i), y = f(j);
        if (x == y)
            return;

        if (r[x] >= r[y])
        {
            h(x, y);
            if (r[x] == r[y])
                r[x]++;
        }
        else
            h(y, x);
    }

    bool k()
    {
        for (int i = 0; i < s.size(); ++i)
            if (s[f(i)] != 0)
                return false;
        return true;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    int t, n, m, a, b;
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        UF uf(n);
        for (int i = 0; i < n; ++i)
            cin >> uf.s[i];
        for (int i = 0; i < m; ++i)
        {
            cin >> a >> b;
            uf.u(a, b);
        }
        if (uf.k())
            cout << "POSSIBLE\n";
        else
            cout << "IMPOSSIBLE\n";
    }
}
