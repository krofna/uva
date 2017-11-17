#include <iostream>
using namespace std;

string G[100];
const int dy[8] = { -1, -1, -1, 0, 0, 1, 1, 1 };
const int dx[8] = { -1, 0, 1, -1, 1, -1, 0, 1 };

int m, n;

void flood(int x, int y)
{
    if (x >= 0 && y >= 0 && x < n && y < m && G[y][x] == '@')
    {
        G[y][x] = '*';
        for (int k = 0; k < 8; ++k)
            flood(x + dx[k], y + dy[k]);
    }
}

int main()
{
    while (cin >> m >> n, m && n)
    {
        for (int i = 0; i < m; ++i)
            cin >> G[i];
        
        int num = 0;
        for (int y = 0; y < m; ++y)
            for (int x = 0; x < n; ++x)
                if (G[y][x] == '@')
                    flood(x, y), num += 1;
        
        cout << num << '\n';
    }
}
