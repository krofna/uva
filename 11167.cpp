#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <sstream>
using namespace std;

typedef vector<int> vi;

const int MAX = 100 + 50000 + 2;

int D[MAX], s = 0, t = 1, M = 2, V = M + 100, u = 1;
vi G[MAX], R[MAX];

int Push(int x, int flow)
{
    if (x == t)
        return flow;
    for (int y : G[x])
        if (R[x][y] > 0 && D[y] == D[x] + 1)
            if (int f = Push(y, min(flow, R[x][y])))
                return R[x][y] -= f, R[y][x] += f, f;
    return D[x] = -1, 0;
}

bool LevelGraph()
{
    queue<int> Q;
    Q.push(s);
    memset(D, -1, sizeof(D));
    D[s] = 0;
    while (!Q.empty())
    {
        int k = Q.front(); Q.pop();
        if (k == t) return true;
        for (int x : G[k])
            if (D[x] == -1 && R[k][x] > 0)
                D[x] = D[k] + 1, Q.push(x);
    }
    return false;
}

void process(int u, int v, int w)
{
    G[u].push_back(v);
    G[v].push_back(u);
    R[u][v] = w;
    R[v][u] = 0;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    R[s].resize(102, 0);
    R[t].resize(MAX, 0);
    for (int i = 0; i < 100; ++i)
        R[M + i].resize(MAX, 0);
    for (int i = 0; i < 50000; ++i)
        R[V + i].resize(102, 0);
    while (cin >> n, n)
    {
        cin >> m;
        int sv = 0;
        for (int i = 0; i < n; ++i)
        {
            int v, a, b;
            cin >> v >> a >> b;
            sv += v;
            process(s, M + i, v);
            for (int j = a; j < b; ++j)
                process(M + i, V + j, 1);
        }
        for (int i = 0; i < 50000; ++i)
            process(V + i, t, m);

        int MF = 0;
        while (LevelGraph())
            while (int f = Push(s, 1e9))
                MF += f;

        cout << "Case " << u++ << ": ";
        if (sv == MF)
        {
            cout << "Yes\n";
            for (int i = M; i < M + n; ++i)
            {
                int f = -1, c = -1, cnt = 0;
                stringstream oss;
                for (int j = 0; j < G[i].size(); ++j)
                {
                    if (G[i][j] != s && !R[i][G[i][j]])
                    {
                        int k = G[i][j] - V;
                        if (k != c)
                        {
                            if (f != -1)
                                oss << "(" << f << ',' << c << ") ";
                            f = k, c = k + 1, cnt++;
                        }
                        else
                            c++;
                    }
                }
                oss << "(" << f << ',' << c << ")\n";
                cout << cnt << ' ' << oss.rdbuf();
            }
        }
        else
            cout << "No\n";
        for (int i = 0; i < MAX; ++i)
            G[i].clear();
    }
}
