#include <iostream>
using namespace std;

int n, m, c, k[20], p[20][20], dp[200][20];

int buy(int q, int l)
{
    if (l < 0) return 201;
    if (q == c) return l;
    if (dp[l][q] != -1) return dp[l][q];
    int mi = 201;
    for (int i = 0; i < k[q]; ++i)
        mi = min(mi, buy(q + 1, l - p[q][i]));
    return dp[l][q] = mi;
}

int main()
{
    cin >> n;
    while (n--)
    {
        cin >> m >> c;
        for (int i = 0; i < c; ++i)
        {
            cin >> k[i];
            for (int j = 0; j < k[i]; ++j)
                cin >> p[i][j];
        }
        fill((int*)dp, (int*)dp + 200 * 20, -1);
        int opt = buy(0, m);
        if (opt == 201)
            cout << "no solution\n";
        else
            cout << m - opt << '\n';
    }
}
