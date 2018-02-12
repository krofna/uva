#include <iostream>
using namespace std;

int A[] = {50, 25, 10, 5, 1};
long long dp[30001][5];

long long f(int n, int i)
{
    if (n < 0) return 0;
    if (i == 5) return n == 0;
    if (dp[n][i]) return dp[n][i];
    return dp[n][i] = f(n - A[i], i) + f(n, i + 1);
}

int main()
{
    int n;
    while (cin >> n)
    {
        cout << "There ";
        if (f(n, 0) == 1)
            cout << "is only 1 way";
        else
            cout << "are " << f(n, 0) << " ways";
        cout << " to produce " << n << " cents change.\n";
    }
}
