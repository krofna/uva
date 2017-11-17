#include <iostream>
#include <limits>
#include <cstring>
#include <algorithm>
using namespace std;

int n, m, A[10][100], dp[10][100], p[10][100], inf = numeric_limits<int>::max();

int f(int r, int c)
{
    if (c == m) return 0;
    if (dp[r][c] != inf) return dp[r][c];
    int opt = inf;
    int B[3] = { r ? r - 1 : n - 1, r == n - 1 ? 0 : r + 1, r};
    sort(B, B + 3);
    for (int i = 0; i < 3; ++i)
    {
        int nf = f(B[i], c + 1);
        if (nf < opt)
            opt = nf, p[r][c] = B[i];
    }
    return dp[r][c] = A[r][c] + opt;
}

int main()
{
    while (cin >> n >> m)
    {
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                cin >> A[i][j];
        fill((int*)dp, (int*)dp + 10 * 100, inf);
        int opt = inf, optr = -1;
        for (int i = 0; i < n; ++i)
        {
            int nf = f(i, 0);
            if (nf < opt)
                opt = nf, optr = i;
        }
        for (int c = 0; c < m; ++c)
        {
            cout << optr + 1;
            if (c < m - 1)
            {
                cout << ' ';
                optr = p[optr][c];
            }
        }
        cout << '\n' << opt << '\n';
    }
}
