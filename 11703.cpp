#include <iostream>
#include <cmath>
using namespace std;

int dp[1000001];

int f(int n)
{
    if (n == 0) return 1;
    if (dp[n]) return dp[n];
    return dp[n] = (f(n - sqrt(n)) + f(log(n)) + f(n * sin(n) * sin(n))) % 1000000;
}

int main()
{
    int n;
    while (cin >> n, n != -1)
        cout << f(n) << '\n';
}
