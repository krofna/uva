#include <iostream>
using namespace std;

int t, A[25][25], inf = 25 * 25;

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
    cin >> t;
    cin.ignore(2);
    while (t--)
    {
        string s;
        int n = 0;
        while (getline(cin, s), !s.empty())
        {
            for (int i = 0; i < s.size(); ++i)
                A[n][i] = s[i] == '1' ? 1 : -inf;
            ++n;
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
        if (t) cout << '\n';
    }
}
