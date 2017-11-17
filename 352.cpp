#include <iostream>
#include <queue>
#include <tuple>
#include <vector>
using namespace std;

vector<string> G;
const int dx[] = { 1, 1, 1, 0, 0, -1, -1, -1 };
const int dy[] = { -1, 0, 1, -1, 1, -1, 0, 1 };
int n, m = 1;

void flood(int x, int y)
{
    queue<pair<int, int> > Q;
    Q.emplace(x, y);
    G[y][x] = '0';
    while (!Q.empty())
    {
        tie(x, y) = Q.front(); Q.pop();
        for (int i = 0; i < 8; ++i)
        {
            int xx = x + dx[i];
            int yy = y + dy[i];
            if (xx >= 0 && xx < n && yy >= 0 && yy < n && G[yy][xx] == '1')
            {
                G[yy][xx] = '0';
                Q.emplace(xx, yy);
            }
        }
    }
}

int main()
{
    while (cin >> n)
    {
        G.resize(n);
        for (int i = 0; i < n; ++i)
            cin >> G[i];

        int cnt = 0;
        for (int y = 0; y < n; ++y)
            for (int x = 0; x < n; ++x)
                if (G[y][x] == '1')
                    cnt++, flood(x, y);
        
        cout << "Image number " << m++ << " contains " << cnt << " war eagles.\n";
    }
}
