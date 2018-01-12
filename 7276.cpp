#include <iostream>
#include <cstring>
using namespace std;

long dp[2001][2001], MOD = 2147483647;
int n, A[2001];

long add(long a, long b)
{
    return (a + b) % MOD;
}

int f(int i, int x)
{
    if (i == n + 1)
        return 1;
    if (dp[i][x] != -1)
        return dp[i][x];
    int a = min(x, A[i - 1]);
    int b = max(x, A[i - 1]);
    if (A[i] > b)
        return dp[i][x] = f(i + 1, a);
    if (A[i] < a)
        return dp[i][x] = f(i + 1, b);
    return dp[i][x] = add(f(i + 1, a), f(i + 1, b));
}

int main()
{
    ios::sync_with_stdio(false);
    while (cin >> n)
    {
        for (int i = 0; i <= n; ++i)
            cin >> A[i];
        memset(dp, -1, sizeof(dp));
        cout << f(2, A[0]) << '\n';
    }
}
