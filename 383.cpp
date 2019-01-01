#include <iostream>
#include <queue>
#include <map>
using namespace std;

int main()
{
    int t;
    cin >> t;
    cout << "SHIPPING ROUTES OUTPUT\n\n";
    for (int T = 1; T <= t; ++T)
    {
        cout << "DATA SET  " << T << "\n\n";
        int m, n, p, s;
        string a, b;
        cin >> m >> n >> p;
        vector<vector<int> > G(m);
        map<string, int> M;
        for (int i = 0; i < m; ++i)
        {
            cin >> a;
            M[a] = i;
        }
        for (int i = 0; i < n; ++i)
        {
            cin >> a >> b;
            int p = M[a], q = M[b];
            G[p].push_back(q);
            G[q].push_back(p);
        }
        for (int i = 0; i < p; ++i)
        {
            cin >> s >> a >> b;
            int p = M[a], q = M[b];
            queue<int> Q;
            Q.push(p);
            vector<int> D(m, -1);
            D[p] = 0;
            while (!Q.empty())
            {
                int k = Q.front();
                Q.pop();
                for (int j : G[k])
                    if (D[j] == -1)
                        D[j] = D[k] + 1, Q.push(j);
            }
            if (D[q] != -1)
                cout << "$" << D[q] * 100 * s << "\n";
            else
                cout << "NO SHIPMENT POSSIBLE\n";
        }
        cout << '\n';
    }
    cout << "END OF OUTPUT\n";
}
