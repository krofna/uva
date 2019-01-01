#include <iostream>
#include <cstring>
using namespace std;

int m, n, p[100], f[100], dp[10200][100];

int g(int c, int k)
{
    if ((c <= 2000 && c > m) || (c > 2000 && c > m + 200))
        return -100;
    if (k == n)
        return 0;
    if (dp[c][k] != -1)
        return dp[c][k];
    return dp[c][k] = max(g(c, k + 1), f[k] + g(c + p[k], k + 1));
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    while (cin >> m >> n)
    {
        for (int i = 0; i < n; ++i)
            cin >> p[i] >> f[i];

        memset(dp, -1, sizeof(dp));
        cout << g(0, 0) << '\n';
    }
}
