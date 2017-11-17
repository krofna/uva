#include <iostream>
#include <algorithm>
#include <iterator>
using namespace std;

const int my[] = { -1, -1, -1, 1, 1, 1, 0, 0 };
const int mx[] = { -1, 0, 1, -1, 0, 1, -1, 1 };

int main()
{
    int n, m, t = 1;
    string G[100];
    while (cin >> n >> m, n > 0 && m > 0)
    {
        if (t != 1) cout << '\n';
        cout << "Field #" << t++ << ":\n";
        for (int y = 0; y < n; ++y)
        {
            cin >> G[y];
            replace(G[y].begin(), G[y].end(), '.', '0');
        }

        for (int y = 0; y < n; ++y)
            for (int x = 0; x < m; ++x)
                for (int i = 0; i < 8; ++i)
                    if (y + my[i] >= 0 && y + my[i] < n &&
                        x + mx[i] >= 0 && x + mx[i] < m &&
                        G[y][x] == '*' && G[y + my[i]][x + mx[i]] != '*')
                        G[y + my[i]][x + mx[i]]++;
        
        copy(G, G + n, ostream_iterator<string>(cout, "\n"));
    }
}
