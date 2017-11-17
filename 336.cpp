#include <iostream>
#include <map>
#include <vector>
#include <queue>
#include <tuple>
#include <set>
using namespace std;

map<int, vector<int> > G;
int nc, a, b, c = 1, x, t;

int bfs(int k, int ttl)
{
    queue<pair<int, int> > Q;
    set<int> F;
    F.insert(k);
    Q.emplace(k, ttl);
    int cnt = 0;
    while (!Q.empty())
    {
        ++cnt;
        tie(x, t) = Q.front(); Q.pop();
        for (int i = 0; t && i < G[x].size(); ++i)
        {
            int ne = G[x][i];
            if (F.find(ne) == F.end())
            {
                F.insert(ne);
                Q.emplace(ne, t - 1);
            }
        }
    }
    return G.size() - cnt;
}

int main()
{
    while (cin >> nc, nc)
    {
        for (int i = 0; i < nc; ++i)
        {
            cin >> a >> b;
            G[a].push_back(b);
            G[b].push_back(a);
        }
        while (cin >> a >> b, a || b)
            cout << "Case " << c++ << ": " << bfs(a, b)
                 << " nodes not reachable from node "
                 << a << " with TTL = " << b << ".\n";
        G.clear();
    }
}
