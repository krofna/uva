#include <iostream>
#include <limits>
using namespace std;

int n, m, x[11], y[11], t, d[11][11], dp[1 << 11][11], inf = numeric_limits<int>::max();

int f(int b, int k)
{
    if (__builtin_popcount(b) == n + 1) return d[k][0];
    if (dp[b][k] != 0) return dp[b][k];
    int ans = inf;
    for (int i = 0; i <= n; ++i)
        if (!(b & (1 << i)))
            ans = min(ans, d[i][k] + f(b | (1 << i), i));
    return dp[b][k] = ans;
}

int main()
{
    cin >> t;
    while (t--)
    {
        cin >> n >> m >> x[0] >> y[0] >> n;
        for (int i = 1; i <= n; ++i)
            cin >> x[i] >> y[i];

        for (int i = 0; i <= n; ++i)
            for (int j = 0; j <= n; ++j)
                if (i != j)
                    d[i][j] = abs(x[i] - x[j]) + abs(y[i] - y[j]);

        fill((int*)dp, (int*)dp + (1 << 11) * 11, 0);
        cout << "The shortest path has length " << f(1, 0) << '\n';
    }
}
