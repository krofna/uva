#include <iostream>
#include <map>
using namespace std;

typedef unsigned long long ull;

int A[4][4], py, px;
int dy[4] = {0, 0, 1, -1};
int dx[4] = {1, -1, 0, 0};
char d[4] = {'R', 'L', 'D', 'U'};
map<ull, int> m;
string s;

int h()
{
    int sum = 0;
    for (int i = 0; i < 4; ++i)
        for (int j = 0; j < 4; ++j)
            if (A[i][j] != 0)
                sum += abs(i - (A[i][j] - 1) / 4) + abs(j - (A[i][j] - 1) % 4);
    return sum;
}

ull state()
{
    ull cs = 0;
    for (int i = 0; i < 4; ++i)
        for (int j = 0; j < 4; ++j)
            cs <<= 4, cs += A[i][j];
    return cs;
}

void move(int& ox, int& oy, int& nx, int& ny)
{
    swap(A[oy][ox], A[ny][nx]);
    swap(oy, ny);
    swap(ox, nx);
}

bool dfs(int c, int l)
{
    int he = h();
    if (he == 0)
        return true;

    if (c + he > l)
        return false;

    ull cs = state();
    auto it = m.find(cs);
    if (it != m.end() && it->second <= c)
        return false;
    m[cs] = c;

    for (int i = 0; i < 4; ++i)
    {
        int xx = px + dx[i];
        int yy = py + dy[i];
        if (xx < 0 || yy < 0 || xx >= 4 || yy >= 4)
            continue;

        s.push_back(d[i]);
        move(px, py, xx, yy);
        if (dfs(c + 1, l))
            return true;
        move(xx, yy, px, py);
        s.pop_back();
    }
    return false;
}

bool good()
{
    int in = 0;
    for (int y = 0; y < 4; y++)
        for (int x = 0; x < 4; x++)
            for (int yy = y; yy < 4; ++yy)
                for (int xx = (yy == y ? x + 1 : 0); xx < 4; ++xx)
                    if (A[yy][xx] && A[y][x] > A[yy][xx])
                        ++in;
    return py % 2 != in % 2;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        for (int i = 0; i < 4; ++i)
        {
            for (int j = 0; j < 4; ++j)
            {
                cin >> A[i][j];
                if (A[i][j] == 0)
                    py = i, px = j;
            }
        }
        if (!good() || !dfs(0, 45))
            cout << "This puzzle is not solvable.\n";
        else
            cout << s << '\n';
        s.clear();
        m.clear();
    }
}
