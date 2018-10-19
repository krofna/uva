#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <algorithm>
using namespace std;

string so, O[] = {"north", "south", "west", "east"};
int dx[] = {0, 0, -1, 1}, dy[] = {-1, 1, 0, 0};
int dx1[] = {0, 0, -2, 1}, dy1[] = {-2, 1, 0, 0};
int dx2[] = {-1, -1, -2, 1}, dy2[] = {-2, 1, -1, -1};
int r[2][2] = {{2, 3}, {0, 1}};
int m, n, a, b, c, d;

int main()
{
    while (cin >> m >> n, m && n)
    {
        int A[50][50], D[50][50][4];
        fill((int*)D, (int*)D + sizeof(D) / sizeof(int), -1);
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                cin >> A[i][j];

        cin >> a >> b >> c >> d >> so;
        int o = find(O, O + 4, so) - O;
        queue<tuple<int, int, int> > Q;
        Q.emplace(a, b, o);
        D[a][b][o] = 0;
        while (!Q.empty())
        {
            tie(a, b, o) = Q.front(), Q.pop();
            for (int i = 0; i < 2; ++i)
                if (D[a][b][r[o / 2][i]] == -1)
                    D[a][b][r[o / 2][i]] = D[a][b][o] + 1,
                        Q.emplace(a, b, r[o / 2][i]);

            for (int i = 0; i < 3; ++i)
            {
                int aa = a + dy[o] + i * dy[o], bb = b + dx[o] + i * dx[o];
                int aa1 = a + dy1[o] + i * dy[o], bb1 = b + dx1[o] + i * dx[o];
                int aa2 = a + dy2[o] + i * dy[o], bb2 = b + dx2[o] + i * dx[o];
                if (aa1 >= 0 && bb1 >= 0 && aa1 < m && bb1 < n &&
                    !A[aa1][bb1] && !A[aa2][bb2])
                {
                    if (D[aa][bb][o] == -1)
                        D[aa][bb][o] = D[a][b][o] + 1, Q.emplace(aa, bb, o);
                }
                else
                    break;
            }
        }
        cout << *min_element(D[c][d], D[c][d] + 4) << '\n';
    }
}
