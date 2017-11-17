#include <iostream>
using namespace std;

string G[100];
int t, n, c = 1;
const int dx[] = {1, 0, 0, -1};
const int dy[] = {0, 1, -1, 0};

void flood(int x, int y)
{
    if (x >= 0 && x < n && y >= 0 && y < n && G[y][x] != '.')
    {
        G[y][x] = '.';    
        for (int k = 0; k < 4; ++k)
            flood(x + dx[k], y + dy[k]);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> t;
    while (t--)
    {
        cin >> n;
        for (int i = 0; i < n; ++i)
            cin >> G[i];

        int k = 0;
        for (int y = 0; y < n; ++y)
            for (int x = 0; x < n; ++x)
                if (G[y][x] == 'x')
                    k++, flood(x, y);
        cout << "Case " << c++ << ": " << k << '\n';
    }
}
