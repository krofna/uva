#include <iostream>
#include <tuple>
#include <stack>
using namespace std;

int G[100][100], n, r, c;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0 ,0, -1, 1};
stack<pair<int, int> > S;

bool vld(int i, int j, int ii, int jj)
{
    return ii >= 0 && ii < r && jj >= 0 && jj < c && G[ii][jj] < G[i][j];
}

void dfs(bool C[100][100], int i, int j)
{
    if (C[i][j])
        return;
    
    C[i][j] = true;
    for (int k = 0; k < 4; ++k)
    {
        int ii = i + dy[k], jj = j + dx[k];
        if (vld(i, j, ii, jj))
            dfs(C, ii, jj);
    }
    S.emplace(i, j);
}

int main()
{
    ios::sync_with_stdio(false);
    string s;
    cin >> n;
    while (n--)
    {
        cin >> s >> r >> c;
        for (int i = 0; i < r; ++i)
            for (int j = 0; j < c; ++j)
                cin >> G[i][j];

        bool C[100][100] = {};
        for (int i = 0; i < r; ++i)
            for (int j = 0; j < c; ++j)
                dfs(C, i, j);

        int D[100][100] = {}, l = 0, x, y;
        while (!S.empty())
        {
            tie(y, x) = S.top(); S.pop();
            for (int k = 0; k < 4; ++k)
            {
                int yy = y + dy[k], xx = x + dx[k];
                if (vld(y, x, yy, xx))
                    l = max(l, D[yy][xx] = max(D[yy][xx], D[y][x] + 1));
            }
        }
        cout << s << ": " << l + 1 << '\n';
    }
}
