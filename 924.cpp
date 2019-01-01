#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main()
{
    int e, n, t, s;
    cin >> e;
    vector<vector<int> > G(e);
    for (int i = 0; i < e; ++i)
    {
        cin >> n;
        G[i].resize(n);
        for (int j = 0; j < n; ++j)
            cin >> G[i][j];
    }
    cin >> t;
    for (int i = 0; i < t; ++i)
    {
        cin >> s;
        queue<int> Q;
        Q.push(s);
        vector<int> D(e, -1);
        vector<int> F(e, 0);
        D[s] = 0;
        while (!Q.empty())
        {
            int k = Q.front();
            Q.pop();
            for (int j = 0; j < G[k].size(); ++j)
            {
                if (D[G[k][j]] == -1)
                {
                    D[G[k][j]] = D[k] + 1;
                    F[D[G[k][j]]]++;
                    Q.push(G[k][j]);
                }
            }
        }
        auto it = max_element(F.begin(), F.end());
        if (*it == 0)
            cout << 0 << '\n';
        else
            cout << *it << ' ' << distance(F.begin(), it) << '\n';
    }
}
