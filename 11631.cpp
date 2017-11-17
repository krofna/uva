#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<bool> vb;
typedef vector<vii> vvii;
typedef greater<ii> gii;
typedef priority_queue<ii, vii, gii> pqii;

void p(pqii& Q, vvii& G, vb& T, int x)
{
    T[x] = true;
    for (int i = 0; i < G[x].size(); ++i)
        if (!T[G[x][i].second])
            Q.push(G[x][i]);
}

int main()
{
    ios::sync_with_stdio(false);
    int m, n, x, y, z;
    while (cin >> m >> n, m || n)
    {
        vvii G(m, vii());
        int c = 0, d = 0;
        for (int i = 0; i < n; ++i)
        {
            cin >> x >> y >> z;
            G[x].emplace_back(z, y);
            G[y].emplace_back(z, x);
            d += z;
        }
        vb T(n, false);
        pqii Q;
        p(Q, G, T, 0);
        while (!Q.empty())
        {
            tie(z, x) = Q.top(); Q.pop();
            if (!T[x])
                c += z, p(Q, G, T, x);
        }
        cout << d - c << '\n';
    }
}
