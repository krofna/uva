#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

typedef vector<int> vi;

struct UF
{
    vi p, s, r;

    UF(int n) : p(n, 0), r(n, 0), s(n, 1)
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
};

int main()
{
    int n, m, k, x, y;
    while (cin >> n >> m, n || m)
    {
        UF uf(n);
        for (int i = 0; i < m; ++i)
        {
            cin >> k >> x;
            for (int j = 1; j < k; ++j)
            {
                cin >> y;
                uf.u(x, y);
            }
        }
        cout << uf.s[uf.f(0)] << '\n';
    }
}
