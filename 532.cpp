#include <iostream>
#include <queue>
#include <tuple>
#include <cstring>
using namespace std;

int l, r, c, sx, sy, sz;
char G[30][30][31];
int D[30][30][30];

const int dx[] = { -1, 0, 0, 1, 0, 0 };
const int dy[] = { 0, -1, 1, 0, 0, 0 };
const int dz[] = { 0, 0, 0, 0, -1, 1 };

int bfs(int x, int y, int z)
{
    queue<tuple<int, int, int> > Q;
    Q.emplace(x, y, z);
    memset(D, 0, sizeof(D));
    while (!Q.empty())
    {
        tie(x, y, z) = Q.front(); Q.pop();
        if (G[z][y][x] == 'E')
            return D[z][y][x];

        for (int k = 0; k < 6; ++k)
        {
            int xx = x + dx[k], yy = y + dy[k], zz = z + dz[k];
            if (xx >= 0 && yy >= 0 && zz >= 0 &&
                xx < c && yy < r && zz < l &&
                G[zz][yy][xx] != '#' && !D[zz][yy][xx])
            {
                D[zz][yy][xx] = D[z][y][x] + 1;
                Q.emplace(xx, yy, zz);
            }
        }
    }
    return -1;
}

int main()
{
    while (cin >> l >> r >> c, l && r && c)
    {
        for (int z = 0; z < l; ++z)
        {
            for (int y = 0; y < r; ++y)
            {
                cin >> G[z][y];
                for (int x = 0; x < c; ++x)
                    if (G[z][y][x] == 'S')
                        tie(sx, sy, sz) = make_tuple(x, y, z);
            }
        }
        int min = bfs(sx, sy, sz);
        if (min != -1)
            cout << "Escaped in " << min << " minute(s).\n";
        else
            cout << "Trapped!\n";
    }
}
