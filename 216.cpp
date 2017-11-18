#include <iostream>
#include <cmath>
#include <limits>
#include <iomanip>
using namespace std;

int n, x[8], y[8], s[1 << 8][9], t = 1;
float d[8][8], dp[1 << 8][8], inf = numeric_limits<float>::max();

float f(int b, int k)
{
    if (__builtin_popcount(b) == n) return 0;
    if (k != -1 && dp[b][k] != 0) return dp[b][k];
    float ans = inf;
    int m = -1;
    for (int i = 0; i < n; ++i)
    {
        if (!(b & (1 << i)))
        {
            float ret = f(b | (1 << i), i);
            if (k != -1) ret += d[i][k];
            if (ret < ans) m = i, ans = ret;
        }
    }
    s[b][k + 1] = m;
    if (k != -1) dp[b][k] = ans;
    return ans;
}

int main()
{
    cout << setprecision(2) << fixed;
    while (cin >> n, n)
    {
        for (int i = 0; i < n; ++i)
            cin >> x[i] >> y[i];

        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                if (i != j)
                    d[i][j] = hypot(x[i] - x[j], y[i] - y[j]) + 16;

        fill((float*)dp, (float*)dp + (1 << 8) * 8, 0);
        float ans = f(0, -1);
        cout << "**********************************************************\n";
        cout << "Network #" << t++ << '\n';
        int k = s[0][0], b = 1 << k;
        while (__builtin_popcount(b) != n)
        {
            int ok = k;
            k = s[b][k + 1];
            b |= 1 << k;
            cout << "Cable requirement to connect ";
            cout << "(" << x[ok] << "," << y[ok] << ") to ";
            cout << "(" << x[k] << "," << y[k] << ")";
            cout << " is " << d[ok][k] << " feet.\n";
        }

        cout << "Number of feet of cable required is " << ans << ".\n";
    }
}
