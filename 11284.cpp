#include <iostream>
#include <limits>
using namespace std;

int t, n, m, p, A[12];
int D[51][51], B[12], dp[1 << 12][12], inf = 1000000000;

int f(int b, int k)
{
    if (__builtin_popcount(b) == p) return D[k][0];
    if (dp[b][k] != inf) return dp[b][k];
    int ans = D[k][0];
    for (int i = 0; i < p; ++i)
        if (!(b & (1 << i)))
            ans = min(ans, D[A[i]][k] - B[i] + f(b | (1 << i), A[i]));
    return dp[b][k] = ans;
}

int read_price()
{
    string s;
    cin >> s;
    size_t d = s.find('.');
    return stoi(s.substr(0, d)) * 100 + stoi(s.substr(d + 1));
}

int main()
{
    cin >> t;
    while (t--)
    {
        cin >> n >> m; n++;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                D[i][j] = (i == j) ? 0 : inf;
        for (int i = 0; i < m; ++i)
        {
            int a, b;
            cin >> a >> b;
            D[a][b] = D[b][a] = min(D[a][b], read_price());
        }
        for (int k = 0; k < n; ++k)
            for (int i = 0; i < n; ++i)
                for (int j = 0; j < n; ++j)
                    D[i][j] = min(D[i][j], D[i][k] + D[k][j]);
        cin >> p;
        for (int i = 0; i < p; ++i)
        {
            int x, y;
            cin >> x;
            A[i] = x;
            B[i] = read_price();
        }
        fill((int*)dp, (int*)dp + (1 << 12) * 12, inf);
        int opt = -f(0, 0), d = opt / 100;
        string cs = to_string(opt % 100);
        cs = string(2 - cs.size(), '0') + cs;
        if (!opt)
            cout << "Don't leave the house\n";
        else
            cout << "Daniel can save $" << d << '.' << cs << '\n';
    }
}
