#include <iostream>
#include <cstring>
using namespace std;

int t, n, g, p[1000], w[1000], a[1000], mw, dp[31][1000], INF = 1000 * 100;

int f(int m, int k)
{
    if (m < 0) return -INF;
    if (k == n) return 0;
    if (dp[m][k] != -1) return dp[m][k];
    return dp[m][k] = max(p[k] + f(m - w[k], k + 1), f(m, k + 1));
}

int main()
{
    ios::sync_with_stdio(false);
    cin >> t;
    while (t--)
    {
        cin >> n;
        for (int i = 0; i < n; ++i)
            cin >> p[i] >> w[i];
        cin >> g;
        int sum = 0;
        memset(dp, -1, sizeof(dp));
        for (int i = 0; i < g; ++i)
        {
            cin >> mw;
            sum += f(mw, 0);
        }
        cout << sum << '\n';
    }
}
