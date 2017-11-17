#include <iostream>
using namespace std;

string G[200];
int dx[] = {-1, 0, -1, 1, 0, 1 };
int dy[] = {-1, -1, 0, 0, 1, 1 };
int n;

bool dfs(int y, int x)
{
    G[y][x] = 'x';
    if (x == n - 1) return true;
    for (int k = 0; k < 6; ++k)
    {
        int xx = x + dx[k];
        int yy = y + dy[k];
        if (xx >= 0 && xx < n && yy >= 0 && yy < n && G[yy][xx] == 'w')
            if (dfs(yy, xx))
                return true;
    }
    return false;
}

bool dfs()
{
    for (int i = 0; i < n; ++i)
        if (G[i][0] == 'w' && dfs(i, 0))
            return true;
    return false;
}

int main()
{
    int t = 1;
    while (cin >> n, n)
    {
        for (int i = 0; i < n; ++i)
            cin >> G[i];
        cout << t++ << " " << (dfs() ? 'W' : 'B') << '\n';
    }
}
