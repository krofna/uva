#include <iostream>
#include <cstring>
using namespace std;

int dp[26 + 1][13 * 27 + 1][26 + 1];

int f(int l, int s, int m)
{
    if (l > 26) return 0;
    if (s > 13 * 27) return 0;
    if (s < 0) return 0;
    if (l == 0) return s == 0;
    if (m > 26) return 0;
    if (dp[l][s][m] != -1) return dp[l][s][m];
    int q = 0;
    for (int i = m; i <= 26; ++i)
        q += f(l - 1, s - i, i + 1);
    return dp[l][s][m] = q;
}

int main()
{
    memset(dp, -1, sizeof(dp));
    int l, s, u = 1;
    while (cin >> l >> s, l || s)
        cout << "Case " << u++ << ": " << f(l, s, 1) << '\n';
}
