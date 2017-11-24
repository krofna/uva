#include <iostream>
using namespace std;

int r, c, b, s, dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, -1, 1}, A[1000], dp[1000][1000], inf = 1000 * 1000;
string G[1000];

void dfs(int x, int y, char p)
{
    if (x < 0 || y < 0 || x >= c || y >= r || G[y][x] != '#')
        return;

    G[y][x] = p;
    for (int i = 0; i < 4; ++i)
        dfs(x + dx[i], y + dy[i], p);
}

int f(int x, int l)
{
    if (x >= c) return l ? inf : 0;
    if (l == 0) return 0;
    if (dp[x][l] != -1) return dp[x][l];
    return dp[x][l] = min(A[x] + f(x + s + 1, l - 1), f(x + 1, l));
}

int main()
{
    ios::sync_with_stdio(false);
    while (cin >> r >> c >> b >> s)
    {
        for (int i = 0; i < r; ++i)
            cin >> G[i];

        dfs(0, 0, '1');
        dfs(0, r - 1, '2');
        fill(A, A + c, 0);
        fill((int*)dp, (int*)dp + 1000 * 1000, -1);
        for (int x = 0; x < c; ++x)
        {
            int y = 0;
            while (G[y][x] != '2') ++y;
            while (G[--y][x] != '1') A[x]++;
        }
        cout << f(0, b) << '\n';
    }
}
