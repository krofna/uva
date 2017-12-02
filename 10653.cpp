#include <iostream>
#include <queue>
#include <tuple>
using namespace std;

int dx[] = {0, 0, 1, -1};
int dy[] = {-1, 1, 0, 0};

int main()
{
    ios::sync_with_stdio(false);
    int r, c;
    while (cin >> r >> c, r || c)
    {
        bool A[1000][1000] = {};
        int rows;
        cin >> rows;
        for (int i = 0; i < rows; ++i)
        {
            int r, n;
            cin >> r >> n;
            for (int j = 0; j < n; ++j)
            {
                int c;
                cin >> c;
                A[r][c] = true;
            }
        }
        int sy, sx, ty, tx;
        cin >> sy >> sx >> ty >> tx;
        queue<tuple<int, int, int> > Q;
        Q.emplace(sy, sx, 0);
        while (!Q.empty())
        {
            auto k = Q.front(); Q.pop();
            int y = get<0>(k);
            int x = get<1>(k);
            int d = get<2>(k);
            if (x == tx && y == ty)
            {
                cout << d << '\n';
                break;
            }
            for (int i = 0; i < 4; ++i)
            {
                int yy = y + dy[i];
                int xx = x + dx[i];
                if (yy >= 0 && xx >= 0 && yy < r && xx < c && !A[yy][xx])
                {
                    Q.emplace(yy, xx, d + 1);
                    A[yy][xx] = true;
                }
            }
        }
    }
}
