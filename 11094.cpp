#include <iostream>
using namespace std;

string G[20];
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
int m, n;
char c;

int flood(int x, int y)
{
    if (y == -1) y = n - 1;
    if (y == n) y = 0;
    if (!(x >= 0 && y >= 0 && x < m && y < n && G[x][y] == c))
        return 0;
    
    G[x][y] = ' ';
    int sum = 1;
    for (int k = 0; k < 4; ++k)
        sum += flood(x + dx[k], y + dy[k]);
    return sum;
}

int main()
{
    int x, y;
    while (cin >> m >> n)
    {
        for (int i = 0; i < m; ++i)
            cin >> G[i];

        cin >> x >> y;
        c = G[x][y];
        flood(x, y);
        
        int mx = 0;
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                mx = max(mx, flood(i, j));
        cout << mx << '\n';
    }
}
