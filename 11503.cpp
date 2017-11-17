#include <iostream>
#include <vector>
#include <numeric>
#include <unordered_map>
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
        cout << s[x] << '\n';
    }

    void u(int i, int j)
    {
        int x = f(i), y = f(j);
        if (x == y)
        {
            cout << s[x] << '\n';
            return;
        }

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
    int n, t;
    cin >> t;
    while (t--)
    {
        cin >> n;
        UF uf(200000);
        unordered_map<string, int> M;
        int k = 0;
        for (int i = 0; i < n; ++i)
        {
            string x, y;
            cin >> x >> y;
            auto a = M.emplace(x, k);
            if (a.second) k++;
            auto b = M.emplace(y, k);
            if (b.second) k++;
            uf.u(a.first->second, b.first->second);
        }
    }
}
