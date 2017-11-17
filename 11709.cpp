#include <iostream>
#include <unordered_map>
#include <vector>
#include <stack>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

stack<int> S;

void scc(vvi& G, vi& N, int u)
{
    N[u] = 1;
    for (int v : G[u])
        if (N[v] == -1)
            scc(G, N, v);
    S.push(u);
}

int main()
{
    ios::sync_with_stdio(false);
    int p, t;
    while (cin >> p >> t, p || t)
    {
        cin.ignore();
        unordered_map<string, int> M;
        for (int i = 0; i < p; ++i)
        {
            string s;
            getline(cin, s);
            M[s] = i;
        }
        vvi G(p), H(p);
        for (int i = 0; i < t; ++i)
        {
            string s, t;
            getline(cin, s);
            getline(cin, t);
            int x = M[s], y = M[t];
            G[x].push_back(y);
            H[y].push_back(x);
        }
        vi N(p, -1);
        for (int i = 0; i < p; ++i)
            if (N[i] == -1)
                scc(G, N, i);
        int num = 0;
        N.assign(p, -1);
        while (!S.empty())
        {
            int k = S.top(); S.pop();
            if (N[k] == -1)
            {
                num++;
                scc(H, N, k);
            }
        }
        cout << num << '\n';
    }
}
