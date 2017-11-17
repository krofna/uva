#include <iostream>
using namespace std;

int t, n, mx;
int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[] = {0, 1, -1, 1, -1, 0, 1, -1};
string G[26];

int dfs(int x, int y)
{
    if (!(x >= 0 && y >= 0 && y < n && x < G[y].size() && G[y][x] == '1'))
        return 0;

    G[y][x] = '0';
    int sum = 1;
    for (int k = 0; k < 8; ++k)
        sum += dfs(x + dx[k], y + dy[k]);
    return sum;
}

int main()
{
    cin >> t;
    cin.ignore(2);
    while (t--)
    {
        n = 0, mx = 0;
        while (getline(cin, G[n]), !G[n].empty()) n++;
        for (int y = 0; y < n; ++y)
            for (int x = 0; x < G[y].size(); ++x)
                mx = max(mx, dfs(x, y));
        cout << mx << '\n';
        if (t) cout << '\n';
    }
}
