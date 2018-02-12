#include <iostream>
#include <cstring>
using namespace std;

int n, A[100], dp[500 * 100 + 1][100];

int f(int m, int i)
{
    if (m < 0) return -500 * 100;
    if (i == n) return 0;
    if (dp[m][i]) return dp[m][i];
    return dp[m][i] = max(f(m - A[i], i + 1) + A[i], f(m, i + 1));
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n;
        int m = 0;
        for (int i = 0; i < n; ++i)
        {
            cin >> A[i];
            m += A[i];
        }
        cout << m - 2 * f(m / 2, 0) << '\n';
        memset(dp, 0, sizeof(dp));
    }
}
