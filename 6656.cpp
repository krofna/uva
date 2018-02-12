#include <iostream>
#include <algorithm>
#include <numeric>
using namespace std;

struct P
{
    int x, y;
};

int main()
{
    int t, n, m, K[100000], M[100000], I[100000], inf = 1000000000;
    ios::sync_with_stdio(false);
    cin >> t;
    P L[100001], R[100001];
    for (int T = 1; T <= t; ++T)
    {
        cin >> n >> m;
        for (int i = 0; i < n; ++i)
        {
            int l, r;
            cin >> l >> r;
            int d = (r - l) / 2;
            L[i] = {l, l + d};
            R[i] = {r - d, r};
        }
        for (int i = 0; i < m; ++i)
            cin >> K[i];

        L[n] = {inf, inf};
        sort(L, L + n + 1, [](P& a, P& b)
        {
            return a.x < b.x;
        });
        R[n] = {0, 0};
        sort(R, R + n + 1, [](P& a, P& b)
        {
            return a.y > b.y;
        });
        iota(I, I + m, 0);
        sort(I, I + m, [&](int a, int b)
        {
            return K[a] < K[b];
        });
        int l = 0;
        for (int i = 0; i < m;)
        {
            if (K[I[i]] >= L[l].x)
            {
                if (K[I[i]] <= L[l].y)
                    M[I[i]] = K[I[i]] - L[l].x, ++i;
                else
                    ++l;
            }
            else
                M[I[i++]] = 0;
        }
        int r = 0;
        for (int i = m - 1; i >= 0;)
        {
            if (R[r].y >= K[I[i]])
            {
                if (K[I[i]] >= R[r].x)
                    M[I[i]] = max(M[I[i]], R[r].y - K[I[i]]), --i;
                else
                    ++r;
            }
            else
                i--;
        }
        cout << "Case " << T << ":\n";
        for (int i = 0; i < m; ++i)
            cout << M[i] << '\n';
    }
}
