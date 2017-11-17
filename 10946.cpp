#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<string> G;
const int dx[] = {1, 0, 0, -1};
const int dy[] = {0, 1, -1, 0};
int h, w, t = 1;

int flood(int x, int y)
{
    char c = G[y][x];
    G[y][x] = '.';
    int cnt = 1;
    for (int k = 0; k < 4; ++k)
    {
        int xx = x + dx[k];
        int yy = y + dy[k];
        if (xx >= 0 && xx < w && yy >= 0 && yy < h && G[yy][xx] == c)
            cnt += flood(xx, yy);
    }
    return cnt;
}

int main()
{
    while (cin >> h >> w, h && w)
    {
        G.resize(h);
        for (int i = 0; i < h; ++i)
            cin >> G[i];

        vector<pair<char, int> > H;
        for (int y = 0; y < h; ++y)
        {
            for (int x = 0; x < w; ++x)
            {
                if (G[y][x] != '.')
                {
                    char z = G[y][x];
                    H.emplace_back(z, flood(x, y));
                }
            }
        }
        sort(H.begin(), H.end(), [](pair<char, int>& a, pair<char, int>& b)
             {
                 if (a.second != b.second)
                     return a.second > b.second;
                 return a.first < b.first;
             });
        cout << "Problem " << t++ << ":\n";
        for (auto& p : H)
            cout << p.first << ' ' << p.second << '\n';
    }
}
