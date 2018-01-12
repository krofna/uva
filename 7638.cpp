#include <iostream>
#include <vector>
#include <cmath>
#include <numeric>
using namespace std;

typedef vector<int> vi;
typedef long long ll;

struct UF
{
    vi r, p;
    int c;
    UF(int n) : r(n, 0), p(n, 0), c(n)
    {
        iota(p.begin(), p.end(), 0);
    }
	
    int f(int x)
    {
        return (p[x] == x ? x : p[x] = f(p[x]));
    }
	
    void u(int i, int j)
    {
        int x = f(i), y = f(j);
        if (x == y)
            return;

        c -= 1;
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

vi P, IsPrime;

void Sieve(ll bound)
{
    IsPrime.assign(bound, 1);
    IsPrime[0] = IsPrime[1] = 0;
    for (ll i = 2; i < bound; ++i)
    {
        if (IsPrime[i])
        {
            for (ll j = i * i; j < bound; j += i)
                IsPrime[j] = 0;

            P.push_back(i);
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    int t, n, k;
    cin >> t;
    Sieve(1000000);
    for (int T = 1; T <= t; ++T)
    {
        cin >> n;
        vi A(1000001, -1);
        UF uf(n);
        for (int j = 0; j < n; ++j)
        {
            cin >> k;
            for (int i = 0; P[i] * P[i] <= k; ++i)
            {
                while (k % P[i] == 0)
                {
                    k /= P[i];
                    if (A[P[i]] != -1)
                        uf.u(A[P[i]], j);
                    A[P[i]] = j;
                }
            }
            if (k != 1)
            {
                if (A[k] != -1)
                    uf.u(A[k], j);
                A[k] = j;
            }
        }
        cout << "Case " << T << ": " << uf.c << '\n';
    }
}
