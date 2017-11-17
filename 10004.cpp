#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
    int n, e, a, b;
    while (cin >> n >> e)
    {
        vector<vector<int> > G(n);
        vector<int> C(n, 2);
        for (int i = 0; i < e; ++i)
        {
            cin >> a >> b;
            G[a].push_back(b);
            G[b].push_back(a);
        }
        bool bi = true;
        queue<int> Q;
        Q.push(0);
        C[0] = 1;
        while (!Q.empty() && bi)
        {
            int x = Q.front();
            Q.pop();
            for (int i = 0; i < G[x].size() && bi; ++i)
            {
                if (C[G[x][i]] == 2)
                {
                    C[G[x][i]] = 1 - C[x];
                    Q.push(G[x][i]);
                }
                else if (C[G[x][i]] == C[x])
                    bi = false;
            }
        }
        if (!bi)
            cout << "NOT ";
        cout << "BICOLORABLE.\n";
    }
}
