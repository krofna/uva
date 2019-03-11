#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define dbg(x) cerr << #x << " = " << x << endl
#define _ << ' ' <<
using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;
using ii = pair<int, int>;
using vii = vector<ii>;
using vvii = vector<vii>;

const int inf = 1e9;

#define flow(src, dst)    (f[src][dst] - f[dst][src])
#define residue(src, dst) (c[src][dst] - flow(src,dst))
vvii gomory_hu(const vvi& c)
{
    const int n = c.size();
    vi p(n, 0), prev, w(n);
    for (int s = 1; s < n; ++s)
    {
        int t = p[s];
        vvi f(n, vi(n));
        int total = 0;
        while (1)
        {
            queue<int> que; que.push(s);
            prev.assign(n, -1); prev[s] = -2;
            while (!que.empty() && prev[t] == -1)
            {
                int u = que.front(); que.pop();
                for (int v = 0; v < n; ++v)
                    if (prev[v] == -1 && residue(u, v) > 0)
                        prev[v] = u, que.push(v);
            }
            if (prev[t] == -1) break;
            int inc = inf;
            for (int v = t, u = prev[v]; u >= 0; v = u, u = prev[v])
                inc = min(inc, residue(u, v));
            for (int v = t, u = prev[v]; u >= 0; v = u, u = prev[v])
                f[u][v] += inc;
            total += inc;
        }
        w[s] = total;
        for (int i = 0; i < n; ++i)
            if (i != s && prev[i] != -1 && p[i] == t)
                p[i] = s;
        if (prev[p[t]] != -1)
            p[s] = p[t], p[t] = s, w[s] = w[t], w[t] = total;
    }
    vvii T(n);
    for (int s = 0; s < n; ++s)
        if (s != p[s])
            T[s].emplace_back(p[s], w[s]),
                T[p[s]].emplace_back(s, w[s]);
    return T;
}

int max_flow(int u, int t, vvii& T, int p = -1, int w = inf)
{
    if (u == t) return w;
    int d = inf;
    for (int i = 0; i < T[u].size(); ++i)
        if (T[u][i].first != p)
            d = min(d, max_flow(T[u][i].first, t, T, u, min(w, T[u][i].second)));
    return d;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t, n;
    cin >> t;
    for (int u = 1; u <= t; ++u)
    {
        cout << "Case #" << u << ":\n";
        cin >> n;
        vvi c(n, vi(n));
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < n; ++j)
                cin >> c[i][j];

        vvii T = gomory_hu(c);
        for(int i = 0; i < n; ++i)
            for(int j = i + 1; j < n; ++j)
                c[i][j] = c[j][i] = max_flow(i, j, T);

        for(int i = 0; i < n; ++i)
        {
            for(int j = 0; j < n; ++j)
                cout << (j ? " " : "") << (i == j ? 0 : c[i][j]);
            cout << '\n';
        }
    }
}
