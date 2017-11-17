#include <iostream>
#include <vector>
#include <queue>
#include <iterator>
#include <tuple>
using namespace std;

vector<string> G;
const int dx[] = {-1, 0, 0, 1};
const int dy[] = {0, 1, -1, 0};

void flood(int x, int y)
{
    queue<pair<int, int> > Q;
    Q.emplace(x, y);
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
                G[yy][xx] = G[y][x];
                Q.emplace(xx, yy);
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    while (cin.peek() != EOF)
    {
        string s;
        while (getline(cin, s), s[0] != '_')
            G.push_back(s);

        char d = 0;
        for (int y = 0; !d && y < G.size(); ++y)
            for (int x = 0; !d && x < G[y].size(); ++x)
                if (G[y][x] != ' ')
                    d = G[y][x];
                
        for (int y = 0; y < G.size(); ++y)
            for (int x = 0; x < G[y].size(); ++x)
                if (G[y][x] != d && G[y][x] != ' ')
                    flood(x, y);

        copy(G.begin(), G.end(), ostream_iterator<string>(cout, "\n"));
        cout << s << '\n';
        G.clear();
    }
}
