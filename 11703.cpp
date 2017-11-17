#include <iostream>
#include <cmath>
using namespace std;

int dp[1000001];

int f(int n)
{
    if (dp[n]) return dp[n];
    return dp[n] = n ? (f(n - sqrt(n)) + f(log(n)) + f(n * sin(n) * sin(n))) % 1000000 : 1;
}

int main()
{
    int n;
    while (cin >> n, n != -1)
        cout << f(n) << '\n';
}
