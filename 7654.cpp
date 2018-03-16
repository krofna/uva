#include <iostream>
#include <array>
#include <map>
#include <vector>
#include <queue>
#include <set>
using namespace std;

typedef array<double, 3> ddd;
typedef array<double, 2> dd;
typedef map<ddd, int> pmap;
typedef map<dd, int> dmap;
typedef vector<int> vi;
typedef set<int> si;
typedef vector<si> vsi;
typedef vector<bool> vb;

void edge(vsi& G, int a, int b)
{
    if (a == b)
        return;

    if (G.size() <= max(a, b))
        G.resize(max(a, b) + 1);

    G[a].insert(b);
    G[b].insert(a);
}

bool bfs(vsi& G)
{
    queue<int> Q;
    vi P(G.size(), -1);
    vb C(G.size(), false);
    for (int i = 0; i < G.size(); ++i)
    {
        if (C[i])
            continue;

        Q.push(i);
        C[i] = true;
        while (!Q.empty())
        {
            int x = Q.front(); Q.pop();
            for (int s : G[x])
            {
                if (C[s] && s != P[x])
                    return true;
                else if (!C[s])
                    C[s] = true, P[s] = x, Q.push(s);
            }
        }
    }
    return false;
}

int main()
{
    int n;
    ios::sync_with_stdio(false);
    while (cin >> n)
    {
        pmap M;
        dmap N;
        vsi G, H;
        int ID = 0, JD = 0;
        for (int k = 0; k < n; ++k)
        {
            int b[2], c[2];
            for (int j = 0; j < 2; ++j)
            {
                ddd p;
                for (int i = 0; i < 3; ++i)
                    cin >> p[i];
                dd q = {p[0], p[1]};
                b[j] = (*M.emplace(p, ID).first).second;
                c[j] = (*N.emplace(q, JD).first).second;
                if (b[j] == ID) ID++;
                if (c[j] == JD) JD++;
            }
            edge(G, b[0], b[1]);
            edge(H, c[0], c[1]);
        }
        if (bfs(G))
            cout << "True closed chains\n";
        else
            cout << "No true closed chains\n";
        if (bfs(H))
            cout << "Floor closed chains\n";
        else
            cout << "No floor closed chains\n";
    }
}
