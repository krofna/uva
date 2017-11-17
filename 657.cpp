#include <iostream>
#include <algorithm>
using namespace std;

string G[50];
int w, h, t = 1, c, C[25 * 25];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

void dfs2(int x, int y)
{
    if (!(x >= 0 && y >= 0 && x < w && y < h && G[y][x] == 'X'))
        return;

    G[y][x] = '*';
    for (int k = 0; k < 4; ++k)
        dfs2(x + dx[k], y + dy[k]);
}

int dfs1(int x, int y)
{
    if (!(x >= 0 && y >= 0 && x < w && y < h && G[y][x] != '.'))
        return 0;

    int sum = 0;
    if (G[y][x] == 'X')
        dfs2(x, y), sum++;

    G[y][x] = '.';
    for (int k = 0; k < 4; ++k)
        sum += dfs1(x + dx[k], y + dy[k]);
    return sum;
}

int main()
{
    while (cin >> w >> h, w && h)
    {
        for (int i = 0; i < h; ++i)
            cin >> G[i];

        c = 0;
        for (int y = 0; y < h; ++y)
            for (int x = 0; x < w; ++x)
                if (int r = dfs1(x, y))
                    C[c++] = r;
        
        cout << "Throw " << t++ << '\n';
        sort(C, C + c);
        for (int i = 0; i < c; ++i)
        {
            if (i) cout << ' ';
            cout << C[i];
        }
        cout << "\n\n";
    }
}
