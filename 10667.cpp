#include <iostream>
using namespace std;

int p, s, n, A[100][100], inf = 100 * 100;

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
        cin >> n >> s;
        fill((int*)A, (int*)A + 100 * 100, 1);
        for (int i = 0; i < s; ++i)
        {
            int r1, r2, c1, c2;
            cin >> r1 >> c1 >> r2 >> c2;
            for (int i = r1 - 1; i < r2; ++i)
                for (int j = c1 - 1; j < c2; ++j)
                    A[i][j] = -inf;
        }
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (j > 0) A[i][j] += A[i][j - 1];
                if (i > 0) A[i][j] += A[i - 1][j];
                if (i > 0 && j > 0) A[i][j] -= A[i - 1][j - 1];
            }
        }
        int ans = -inf;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                for (int y = i; y < n; ++y)
                    for (int x = j; x < n; ++x)
                        ans = max(ans, f(i, j, y, x));
        cout << (ans == -inf ? 0 : ans) << '\n';
    }
}
