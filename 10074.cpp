#include <iostream>
using namespace std;

int m, n, A[100][100], inf = 100 * 100;

int f(int i, int j, int y, int x)
{
    int r = A[y][x];
    if (j > 0) r -= A[y][j - 1];
    if (i > 0) r -= A[i - 1][x];
    if (i > 0 && j > 0) r += A[i - 1][j - 1];
    return r;
}

int main()
{
    while (cin >> m >> n, m || n)
    {
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                cin >> A[i][j];
                A[i][j] = A[i][j] ? -inf : 1;
                if (j > 0) A[i][j] += A[i][j - 1];
                if (i > 0) A[i][j] += A[i - 1][j];
                if (i > 0 && j > 0) A[i][j] -= A[i - 1][j - 1];
            }
        }
        int ans = -inf;
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                for (int y = i; y < m; ++y)
                    for (int x = j; x < n; ++x)
                        ans = max(ans, f(i, j, y, x));
        cout << (ans == -inf ? 0 : ans) << '\n';
    }
}
