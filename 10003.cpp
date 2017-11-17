#include <iostream>
#include <cstring>
using namespace std;

int A[52], l, n, dp[52][52];

int rec(int lo, int hi)
{
    if (lo > hi) return 0;
    if (dp[lo][hi]) return dp[lo][hi];
    int mi = 50000;
    int pr = A[hi + 1] - A[lo - 1];
    for (int i = lo; i <= hi; ++i)
        mi = min(mi, rec(lo, i - 1) + rec(i + 1, hi));
    return dp[lo][hi] = pr + mi;
}

int main()
{
    while (cin >> l, l)
    {
        cin >> n;
        for (int i = 1; i <= n; ++i)
            cin >> A[i];
        A[0] = 0;
        A[n + 1] = l;
        memset(dp, 0, sizeof(dp));
        cout << "The minimum cutting is " << rec(1, n) << ".\n";
    }
}
