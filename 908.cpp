#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <tuple>
using namespace std;

typedef vector<int> vi;
typedef vector<tuple<int, int, int> > viii;

struct UF
{
    vi p, r;

    UF(int n) : p(n, 0), r(n, 0)
    {
        iota(p.begin(), p.end(), 0);
    }

    int f(int i)
    {
        return (p[i] == i) ? i : (p[i] = f(p[i]));
    }

    bool u(int i, int j)
    {
        int x = f(i), y = f(j);
        if (x == y)
            return false;

        if (r[x] >= r[y])
        {
            p[y] = x;
            if (r[x] == r[y])
                r[x]++;
        }
        else
            p[x] = y;
        
        return true;
    }
};

int main()
{
    int n, a, b, w, k, m, l = 0;
    while (cin >> n)
    {
        if (l++) cout << '\n';        
        viii E;
        int o = 0, c = 0;
        for (int i = 0; i < n - 1; ++i)
        {
            cin >> a >> b >> w;
            E.emplace_back(w, a, b);
            o += w;
        }
        cin >> k;
        for (int i = 0; i < k; ++i)
        {
            cin >> a >> b >> w;
            E.emplace_back(w, a, b);
        }
        cin >> m;
        for (int i = 0; i < m; ++i)
            cin >> a >> b >> w;
        UF uf(E.size());
        sort(E.begin(), E.end());
        for (auto& t : E)
        {
            tie(w, a, b) = t;
            if (uf.u(a - 1, b - 1))
                c += w;
        }
        cout << o << '\n' << c << '\n';
    }
}
