#include <iostream>
using namespace std;

int n, A[100][100];

inline int f(int i, int j, int y, int x)
{
    int r = A[y][x];
    if (j > 0) r -= A[y][j - 1];
    if (i > 0) r -= A[i - 1][x];
    if (i > 0 && j > 0) r += A[i - 1][j - 1];
    return r;
}

inline int g(int i, int j)
{
    int ans = -127 * 100 * 100, sum = 0;
    for (int k = 0; k < n; ++k)
    {
        sum += f(k, i, k, j);
        ans = max(ans, sum);
        sum = max(sum, 0);
    }
    return ans;
}

int main()
{
    cin >> n;
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
    int ans = -127 * 100 * 100;
    for (int i = 0; i < n; ++i)
        for (int j = i; j < n; ++j)
            ans = max(ans, g(i, j));
    cout << ans << '\n';
}
