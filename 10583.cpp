#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

typedef vector<int> vi;

struct UF
{
    vi p, r;
    int k;
    
    UF(int n) : p(n, 0), r(n, 0), k(n)
    {
        iota(p.begin(), p.end(), 0);
    }

    int f(int i)
    {
        return (p[i] == i) ? i : (p[i] = f(p[i]));
    }

    void u(int i, int j)
    {
        int x = f(i), y = f(j);
        if (x == y)
            return;

        k -= 1;
        if (r[x] >= r[y])
        {
            p[y] = x;
            if (r[x] == r[y])
                r[x]++;
        }
        else
            p[x] = y;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    int n, m, a, b, t = 1;
    while (cin >> n >> m, n || m)
    {
        UF uf(n);
        for (int i = 0; i < m; ++i)
        {
            cin >> a >> b;
            uf.u(a - 1, b - 1);
        }
        cout << "Case " << t++ << ": " << uf.k << '\n';
    }
}
