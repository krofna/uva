#include <iostream>
#include <vector>
#include <sstream>
#include <numeric>
using namespace std;

typedef vector<int> vi;

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

    void u(int i, int j)
    {
        int x = f(i), y = f(j);
        if (x == y)
            return;

        if (r[x] >= r[y])
        {
            p[y] = x;
            if (r[x] == r[y])
                r[x]++;
        }
        else
            p[x] = y;
    }

    bool s(int i, int j)
    {
        return f(i) == f(j);
    }
};

int main()
{
    ios::sync_with_stdio(false);
    int t, n, a, b;
    cin >> t;
    while (t--)
    {
        cin >> n;
        UF uf(n);
        cin.ignore();
        string s;
        int su = 0, un = 0;
        while (getline(cin, s), !s.empty())
        {
            istringstream iss(s);
            char c;
            iss >> c >> a >> b;
            if (c == 'c')
                uf.u(a - 1, b - 1);
            else if (uf.s(a - 1, b - 1))
                su++;
            else
                un++;
        }
        cout << su << ',' << un << '\n';
        if (t) cout << '\n';
    }
}
