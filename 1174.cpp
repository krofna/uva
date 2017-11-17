#include <iostream>
#include <map>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<vii> vvii;
typedef vector<bool> vb;
typedef greater<ii> gii;
typedef map<string, int> msi;
typedef priority_queue<ii, vii, gii> pqii;

void p(vvii& G, pqii& Q, vb& T, int x)
{
    T[x] = true;
    for (int i = 0; i < G[x].size(); ++i)
        if (!T[G[x][i].second])
            Q.emplace(G[x][i]);
}

int main()
{
    ios::sync_with_stdio(false);
    int t, n, m, w, x, y;
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        int k = 0;
        msi M;
        vvii G(n, vii());
        for (int i = 0; i < m; ++i)
        {
            string a, b;
            cin >> a >> b >> w;
            auto p = M.emplace(a, k);
            if (p.second) k++;
            auto q = M.emplace(b, k);
            if (q.second) k++;
            x = p.first->second;
            y = q.first->second;
            G[x].emplace_back(w, y);
            G[y].emplace_back(w, x);
        }
        pqii Q;
        vb T(n, false);
        p(G, Q, T, 0);
        int c = 0;
        while (!Q.empty())
        {
            tie(w, x) = Q.top(); Q.pop();
            if (!T[x])
                c += w, p(G, Q, T, x);
        }
        cout << c << '\n';
        if (t) cout << '\n';
    }
}
