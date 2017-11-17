#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;

vector<string> G;
const int dx[] = {-1, 0, 0, 1};
const int dy[] = {0, 1, -1, 0};

void flood(int x, int y)
{
    queue<pair<int, int> > Q;
    Q.emplace(x, y);
    G[y][x] = '#';
    while (!Q.empty())
    {
        tie(x, y) = Q.front(); Q.pop();
        for (int k = 0; k < 4; ++k)
        {
            int xx = x + dx[k];
            int yy = y + dy[k];
            if (xx >= 0 && yy >= 0 && yy < G.size() &&
                xx < G[yy].size() && G[yy][xx] == ' ')
            {
                G[yy][xx] = '#';
                Q.emplace(xx, yy);
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    cin.ignore();
    for (int k = 0; k < n; ++k)
    {
        string s;
        while (getline(cin, s), s[0] != '_')
            G.push_back(s);

        for (int y = 0; y < G.size(); ++y)
            for (int x = 0; x < G[y].size(); ++x)
                if (G[y][x] == '*')
                    flood(x, y);

        for (int y = 0; y < G.size(); ++y)
            cout << G[y] << '\n';

        cout << s << '\n';
        G.clear();
    }
}
