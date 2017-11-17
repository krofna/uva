#include <iostream>
#include <vector>
#include <numeric>
#include <unordered_map>
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
    int n, m;
    string x, y;
    while (cin >> n >> m, n || m)
    {
        UF uf(n);
        unordered_map<string, int> M;
        for (int i = 0; i < n; ++i)
        {
            cin >> x;
            M[x] = i;
        }
        for (int i = 0; i < m; ++i)
        {
            cin >> x >> y;
            uf.u(M[x], M[y]);
        }
        cout << uf.m << '\n';
    }
}
