#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

typedef vector<int> vi;

struct UF
{
    vi p, s, r;
    int m;

    UF(int n) : p(n, 0), r(n, 0), s(n, 1), m(1)
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
        m = max(m, s[x]);
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
};

int main()
{
    ios::sync_with_stdio(false);
    int n, m, x, y, t;
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        UF uf(n);
        for (int i = 0; i < m; ++i)
        {
            cin >> x >> y;
            uf.u(x - 1, y - 1);
        }
        cout << uf.m << '\n';
    }
}
