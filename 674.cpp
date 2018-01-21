#include <iostream>
using namespace std;

const int c[5] = {50, 25, 10, 5, 1};
int dp[8000][5];

int f(int n, int k)
{
    if (k == 5) return 0;
    if (n < 0) return 0;
    if (n == 0) return 1;
    if (dp[n][k] != 0) return dp[n][k];
    return dp[n][k] = f(n - c[k], k) + f(n, k + 1);
}

int main()
{
    int n;
    ios::sync_with_stdio(false);
    while (cin >> n)
        cout << f(n, 0) << '\n';
}
