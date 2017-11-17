#include <iostream>
#include <queue>
#include <tuple>
#include <cstring>
#include <cstdlib>
using namespace std;

char G[40][90];
const int dx[] = {-1, 0, 0, 1};
const int dy[] = {0, 1, -1, 0};
int t, m;
string s;

void flood(int x, int y)
{
    G[y][x] = ' ';
    queue<pair<int, int> > Q;
    Q.emplace(x, y);
    bool B[40][90] = {};
    B[y][x] = true;
    while (!Q.empty())
    {
        tie(x, y) = Q.front(); Q.pop();
        for (int k = 0; k < 4; ++k)
        {
            int xx = x + dx[k], yy = y + dy[k];
            if (xx >= 0 && yy >= 0 && yy < m && xx <= 80)
            {
                if ((G[yy][xx] == ' ' || G[yy][xx] == '\0') && !B[yy][xx])
                {
                    B[yy][xx] = true;
                    Q.emplace(xx, yy);
                }
                else if (G[yy][xx] != ' ' && G[yy][xx] != '\0' && G[yy][xx] != '#')
                    G[y][x] = '#';
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> t;
    cin.ignore();
    for (int k = 0; k < t; ++k)
    {
        m = 0;
        memset(G, 0, sizeof(G));
        while (getline(cin, s), s[0] != '_')
            memcpy(G[m++], s.c_str(), s.size());
       
        for (int y = 0; y < m; ++y)
            for (int x = 0; x < 80; ++x)
                if (G[y][x] == '*')
                    flood(x, y);

        for (int y = 0; y < m; ++y)
        {
            int x;
            for (x = 80; x >= 0 && (!G[y][x] || G[y][x] == ' '); --x);
            
            for (int i = 0; i <= x; ++i)
                cout << (G[y][i] ? G[y][i] : ' ');
            cout << '\n';
        }
        cout << s << '\n';
    }
}
