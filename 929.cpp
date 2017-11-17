#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;

int G[1000][1000];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

typedef tuple<int, int, int> iii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<iii> viii;

int main()
{
    ios::sync_with_stdio(false);
    int t, n, m, x, y, w;
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                cin >> G[i][j];

        priority_queue<iii, viii, greater<iii>> Q;
        Q.emplace(G[0][0], 0, 0);
        vvi D(n, vi(m, 10 * n * m));
        D[0][0] = G[0][0];
        while (!Q.empty())
        {
            tie(w, x, y) = Q.top(); Q.pop();
            if (w > D[y][x])
                continue;

            if (x == m - 1 && y == n - 1)
                break;

            for (int k = 0; k < 4; ++k)
            {
                int xx = x + dx[k], yy = y + dy[k];
                if (xx >= 0 && yy >= 0 && xx < m && yy < n)
                {
                    if (D[y][x] + G[yy][xx] < D[yy][xx])
                    {
                        D[yy][xx] = D[y][x] + G[yy][xx];
                        Q.emplace(D[yy][xx], xx, yy);
                    }
                }
            }
        }
        cout << D[n - 1][m - 1] << '\n';
    }
}
