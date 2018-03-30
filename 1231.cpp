#include <iostream>
#include <cstring>
using namespace std;

int c, t, h, f, k, n, A[2001][2001], dp[2001][2001], dp2[2001];

int g(int tr, int in)
{
    if (tr < 0 || tr >= t || in < 0) return 0;
    if (dp[tr][in] != -1) return dp[tr][in];
    if (dp2[in] == -1)
        for (int i = 0; i < t; ++i)
            dp2[in] = max(dp2[in], g(i, in - f));
    return dp[tr][in] = A[tr][in] + max(dp2[in], g(tr, in - 1));
}

int main()
{
    ios::sync_with_stdio(false);
    cin >> c;
    while (c--)
    {
        memset(dp, -1, sizeof(dp));
        memset(dp2, -1, sizeof(dp2));
        memset(A, 0, sizeof(A));
        cin >> t >> h >> f;
        for (int i = 0; i < t; ++i)
        {
            cin >> k;
            for (int j = 0; j < k; ++j)
                cin >> n, A[i][n]++;
        }
        int mx = 0;
        for (int i = 0; i < t; ++i)
            mx = max(mx, g(i, h));
        cout << mx << '\n';
    }
}
