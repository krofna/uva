#include <iostream>
using namespace std;

typedef long long ll;
ll t, n, m, k, A[100][100];

inline void f(int i, int j, int y, int x, ll& ar, ll& pr)
{
    ll r = A[y][x];
    if (j > 0) r -= A[y][j - 1];
    if (i > 0) r -= A[i - 1][x];
    if (i > 0 && j > 0) r += A[i - 1][j - 1];
    ll a = (y - i + 1) * (x - j + 1);
    if (r <= k && (a > ar || (a == ar && r < pr)))
        ar = a, pr = r;
}

int main()
{
    cin >> t;
    for (int T = 1; T <= t; ++T)
    {
        cin >> n >> m >> k;
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                cin >> A[i][j];
                if (j > 0) A[i][j] += A[i][j - 1];
                if (i > 0) A[i][j] += A[i - 1][j];
                if (i > 0 && j > 0) A[i][j] -= A[i - 1][j - 1];
            }
        }
        ll ar = 0, pr = k;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                for (int y = i; y < n; ++y)
                    for (int x = j; x < m; ++x)
                        f(i, j, y, x, ar, pr);
        cout << "Case #" << T << ": " << ar << " " << (ar ? pr : 0) << '\n';
    }
}
