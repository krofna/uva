#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

vector<string> G;
const int dx[] = {1, 0, 0, -1};
const int dy[] = {0, 1, -1, 0};
int h, w;

void flood(int x, int y)
{
    char c = G[y][x];
    G[y][x] = '.';
    for (int k = 0; k < 4; ++k)
    {
        int xx = x + dx[k];
        int yy = y + dy[k];
        if (xx >= 0 && xx < w && yy >= 0 && yy < h && G[yy][xx] == c)
            flood(xx, yy);
    }
}

void main2()
{
    cin >> h >> w;
    G.resize(h);
    for (int i = 0; i < h; ++i)
        cin >> G[i];

    int cnt[26] = {}, ind[26];
    for (int y = 0; y < h; ++y)
    {
        for (int x = 0; x < w; ++x)
        {
            if (G[y][x] != '.')
            {
                int z = G[y][x] - 'a';
                flood(x, y);
                cnt[z]++;
            }
        }
    }
    iota(ind, ind + 26, 0);
    stable_sort(ind, ind + 26, [&](int j, int k){return cnt[j] > cnt[k];});
    for (int i = 0; i < 26 && cnt[ind[i]]; ++i)
        cout << char('a' + ind[i]) << ": " << cnt[ind[i]] << '\n';
}

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cout << "World #" << i << '\n';
        main2();
    }
}
