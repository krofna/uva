/*
TODO
http://www.geeksforgeeks.org/tarjan-algorithm-find-strongly-connected-components/
https://en.wikipedia.org/wiki/Tarjan%27s_strongly_connected_components_algorithm
https://github.com/mitchi/SCC/blob/master/scc/tarjan%20scc.cpp

 */
#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef vector<string> vs;
typedef stack<int> si;

si S;
vvi G;
vs W;
int c;

void scc(vi& N, vi& L, vb& V, int u)
{
    L[u] = N[u] = c++;
    S.push(u);
    V[u] = true;
    for (int v : G[u])
    {
        if (N[v] == -1)
            scc(N, L, V, v);
        if (V[v])
            L[u] = min(L[u], L[v]);
    }

    if (L[u] == N[u])
    {
        while (1)
        {
            int v = S.top(); S.pop();
            cout << W[v];
            V[v] = false;
            if (u == v) break;
            else cout << ", ";
        }
        cout << '\n';
    }
}

int main()
{
    ios::sync_with_stdio(false);
    int m, n, t = 1;
    while (cin >> n >> m, n || m)
    {
        if (t > 1) cout << '\n';
        cout << "Calling circles for data set " << t++ << ":\n";
        G.assign(n, vi());
        W.resize(n);
        unordered_map<string, int> M;
        int k = 0;
        for (int i = 0; i < m; ++i)
        {
            string a, b;
            cin >> a >> b;
            auto p = M.emplace(a, k);
            if (p.second) W[k++] = a;
            auto q = M.emplace(b, k);
            if (q.second) W[k++] = b;
            int x = p.first->second;
            int y = q.first->second;
            G[x].push_back(y);
        }
        vi L(n, -1), N(n, -1);
        vb V(n, false);
        c = 0;
        for (int i = 0; i < n; ++i)
            if (N[i] == -1)
                scc(N, L, V, i);
    }
}
