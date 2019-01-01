#include <iostream>
#include <map>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

int R[100][100], t, n, m;
vvi G;
vi P;

map<string, int> M = {{"XS", 0},{"S", 1},{"M", 2},{"L", 3},{"XL", 4},{"XXL", 5}};

bool AP()
{
    queue<int> Q;
    P.assign(2 + 6 + m, -1);
    Q.push(0);
    while (!Q.empty())
    {
        int k = Q.front(); Q.pop();
        if (k == 1)
            return true;

        for (int x : G[k])
            if (P[x] == -1 && R[k][x] > 0)
                P[x] = k, Q.push(x);
    }
    return false;
}

void edge(int u, int v, int w = 1)
{
    G[u].push_back(v);
    G[v].push_back(u);
    R[u][v] = w;
}

int main()
{
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        memset(R, 0, sizeof(R));
        G.assign(2 + 6 + m, vi());
        for (int i = 0; i < 6; ++i)
            edge(2 + i, 1, n / 6);

        for (int i = 0; i < m; ++i)
        {
            string a, b;
            cin >> a >> b;
            int c = 2 + M[a], d = 2 + M[b];
            edge(0, 8 + i);
            edge(8 + i, c);
            edge(8 + i, d);
        }
        int MF = 0;
        while (AP())
        {
            int aug = 1e9;
            for (int x = 1; x != 0; x = P[x])
                aug = min(aug, R[P[x]][x]);

            for (int x = 1; x != 0; x = P[x])
                R[P[x]][x] -= aug, R[x][P[x]] += aug;

            MF += aug;
        }
        cout << (MF == m ? "YES" : "NO") << '\n';
    }
}
