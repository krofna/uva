#include <iostream>
using namespace std;

int p, n, A[75 * 2][75 * 2];

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
    cin >> p;
    while (p--)
    {
        cin >> n;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                cin >> A[i][j], A[i + n][j] = A[i + n][j + n] = A[i][j + n] = A[i][j];

        for (int i = 0; i < 2 * n; ++i)
        {
            for (int j = 0; j < 2 * n; ++j)
            {
                if (j > 0) A[i][j] += A[i][j - 1];
                if (i > 0) A[i][j] += A[i - 1][j];
                if (i > 0 && j > 0) A[i][j] -= A[i - 1][j - 1];
            }
        }
        int ans = -75 * 75 * 100;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                for (int y = i; y < i + n; ++y)
                    for (int x = j; x < j + n; ++x)
                        ans = max(ans, f(i, j, y, x));
        cout << ans << '\n';
    }
}
