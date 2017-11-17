#include <iostream>
#include <limits>
using namespace std;

typedef long long ll;

ll A[20][20][20], t, a, b, c, inf = numeric_limits<ll>::min();

inline void in(int i, int j, int k)
{
    cin >> A[i][j][k];
    if (j > 0) A[i][j][k] += A[i][j - 1][k];
    if (k > 0) A[i][j][k] += A[i][j][k - 1];
    if (j > 0 && k > 0) A[i][j][k] -= A[i][j - 1][k - 1];
}

inline ll g(int i, int j, int k, int y, int x)
{
    ll val = A[i][y][x];
    if (j > 0) val -= A[i][j - 1][x];
    if (k > 0) val -= A[i][y][k - 1];
    if (j > 0 && k > 0) val += A[i][j - 1][k - 1];
    return val;
}

inline ll f(int j, int k, int y, int x)
{
    ll opt = inf, sum = 0;
    for (int i = 0; i < a; ++i)
    {
        sum += g(i, j, k, y, x);
        opt = max(opt, sum);
        sum = max(sum, 0LL);
    }
    return opt;
}

int main()
{
    cin >> t;
    while (t--)
    {
        cin >> a >> b >> c;
        for (int i = 0; i < a; ++i)
            for (int j = 0; j < b; ++j)
                for (int k = 0; k < c; ++k)
                    in(i, j, k);

        ll opt = inf;
        for (int j = 0; j < b; ++j)
            for (int k = 0; k < c; ++k)
                for (int y = j; y < b; ++y)
                    for (int x = k; x < c; ++x)
                        opt = max(opt, f(j, k, y, x));

        cout << opt << '\n';
        if (t) cout << '\n';
    }
}
