#include <iostream>
#include <queue>
#include <tuple>
using namespace std;

const int dx[] = { 1, 1, 2, 2, -1, -1, -2, -2};
const int dy[] = { -2, 2, -1, 1, -2, 2, -1, 1};

int main()
{
    string a, b;
    while (cin >> a >> b)
    {
        int x1 = a[0] - 'a', y1 = a[1] - '1', x2 = b[0] - 'a', y2 = b[1] - '1';
        int G[8][8] = {}, x, y;
        queue<pair<int, int> > Q;
        Q.emplace(x1, y1);
        while (!G[x2][y2] && !(x1 == x2 && y1 == y2))
        {
            tie(x, y) = Q.front(); Q.pop();
            for (int i = 0; i < 8; ++i)
            {
                int nx = x + dx[i], ny = y + dy[i];
                if (nx >= 0 && nx < 8 && ny >= 0 && ny < 8 && !G[nx][ny])
                {
                    G[nx][ny] = G[x][y] + 1;
                    Q.emplace(nx, ny);
                }
            }
        }
        cout << "To get from " << a << " to " << b << " takes " << G[x2][y2] << " knight moves.\n";
    }
}
