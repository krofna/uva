#include <iostream>
#include <cstring>
using namespace std;

int m, n, t, dp[10000], dp2[10000];

int f(int t)
{
    if (t == 0) return 0;
    if (dp[t]) return dp[t];
    return dp[t] = max(t >= m ? m + f(t - m) : 0, t >= n ? n + f(t - n) : 0);
}

int g(int t)
{
    if (t < 0) return -10000;
    if (t == 0) return 0;
    if (dp2[t] != -1) return dp2[t];
    return dp2[t] = 1 + max(g(t - n), g(t - m));
}

int main()
{
    ios::sync_with_stdio(false);
    while (cin >> m >> n >> t)
    {
        memset(dp, 0, sizeof(dp));
        memset(dp2, -1, sizeof(dp2));
        if (t - f(t))
            cout << g(f(t)) << ' ' << t - f(t);
        else
            cout << g(t);
        cout << '\n';
    }
}
