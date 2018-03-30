#include <iostream>
#include <cstring>
using namespace std;

typedef unsigned long long ll;

ll dp[61][61];

ll f(int n, int b)
{
    if (n <= 1) return 1;
    if (dp[n][b] != -1) return dp[n][b];
    ll s = 1;
    for (int i = 1; i <= b; ++i)
        s += f(n - i, b);
    return dp[n][b] = s;
}

int main()
{
    memset(dp, -1, sizeof(dp));
    int n, b, u = 1;
    while (cin >> n >> b, n <= 60)
        cout << "Case " << u++ << ": " << f(n, b) << '\n';
}
