#include <iostream>
using namespace std;

int m, n, A[1000][1000], sum;

int f(int i, int j, int y, int x)
{
    int r = A[y][x];
    if (j > 0) r -= A[y][j - 1];
    if (i > 0) r -= A[i - 1][x];
    if (i > 0 && j > 0) r += A[i - 1][j - 1];
    sum += r;
    return r;
}

int main()
{
    bool g = false;
    while (cin >> n >> m)
    {
        if (g) cout << '\n';
        g = true;
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                cin >> A[i][j];
                if (j > 0) A[i][j] += A[i][j - 1];
                if (i > 0) A[i][j] += A[i - 1][j];
                if (i > 0 && j > 0) A[i][j] -= A[i - 1][j - 1];
            }
        }
        sum = 0;
        for (int i = 0; i < n - m + 1; ++i)
            for (int j = 0; j < n - m + 1; ++j)
                cout << f(i, j, i + m - 1, j + m - 1) << '\n';
        cout << sum << '\n';
    }
}
