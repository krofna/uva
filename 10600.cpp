#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <algorithm>
#include <numeric>
using namespace std;

typedef tuple<int, int, int> iii;
typedef vector<iii> viii;

struct UF
{
    vector<int> p;
    UF(int n) : p(n, 0)
    {
        iota(p.begin(), p.end(), 0);
    }

    int f(int x)
    {
        return (p[x] == x ? x : p[x] = f(p[x]));
    }

    void u(int i, int j)
    {
        p[f(i)] = f(j);
    }

    bool s(int i, int j)
    {
        return f(i) == f(j);
    }
};

int t, n, m;
iii ig;

int kruskal(viii& E, viii* S = nullptr)
{
    UF uf(n);
    int mst = 0;
    for (auto& t : E)
    {
        int w, a, b;
        tie(w, a, b) = t;
        if (t != ig && !uf.s(a, b))
        {
            mst += w;
            uf.u(a, b);
            if (S) S->push_back(t);
        }
    }
    return all_of(uf.p.begin(), uf.p.end(), [&](int a)
    {
        return uf.s(a, 0);
    }) ? mst : 1e9;
}

int main()
{
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        viii E, S;
        for (int i = 0; i < m; ++i)
        {
            int a, b, c;
            cin >> a >> b >> c, a--, b--;
            E.emplace_back(c, a, b);
        }
        sort(E.begin(), E.end());
        UF uf(n);
        int mst = kruskal(E, &S), mst2 = 1e9;
        for (auto& p : S)
            ig = p, mst2 = min(mst2, kruskal(E));
        cout << mst << ' ' << mst2 << '\n';
    }
}
