#include <iostream>
#include <cstring>
using namespace std;

int n, q, t = 1, d, m;
long long A[200], dp[20][10][200];

int mod(int a)
{
    int r = a % d;
    return r < 0 ? r + d : r;
}

int f(int s, int c, int k)
{
    if (k == n + 1)
        return 0;
    if (c == m)
        return s % d == 0;
    if (dp[s][c][k] != -1)
        return dp[s][c][k];
    return dp[s][c][k] = f(s, c, k + 1) + f(mod(s + A[k]), c + 1, k + 1);
}

int main()
{
    while (cin >> n >> q, n + q)
    {
        for (int i = 0; i < n; ++i)
            cin >> A[i];

        cout << "SET " << t++ << ":\n";
        for (int i = 0; i < q; ++i)
        {
            cin >> d >> m;
            memset(dp, -1, sizeof(dp));
            cout << "QUERY " << i + 1 << ": " << f(0, 0, 0) << '\n';
        }
    }
}
