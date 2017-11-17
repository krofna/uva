#include <iostream>
using namespace std;

string G[100];
int r, c;

const int dx[] = {1, 1, 1, -1, -1, -1, 0, 0};
const int dy[] = {-1, 0, 1, -1, 0, 1, -1, 1};

int flood(int x, int y)
{
    int ret = 0;
    if (x >= 0 && y >= 0 && x < c && y < r && G[y][x] == '*')
    {
        ret += 1;
        G[y][x] = '.';
        for (int i = 0; i < 8; ++i)
            ret += flood(x + dx[i], y + dy[i]);
    }
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    while (cin >> r >> c, r && c)
    {
        for (int i = 0; i < r; ++i)
            cin >> G[i];

        int s = 0;
        for (int y = 0; y < r; ++y)
            for (int x = 0; x < c; ++x)
                if (flood(x, y) == 1)
                    ++s;
        
        cout << s << '\n';
    }
}
