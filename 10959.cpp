#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int p, d;
        cin >> p >> d;
        vector<vector<int> > G(p);
        for (int i = 0; i < d; ++i)
        {
            int a, b;
            cin >> a >> b;
            G[a].push_back(b);
            G[b].push_back(a);
        }
        vector<int> D(p, -1);
        D[0] = 0;
        queue<int> Q;
        Q.push(0);
        while (!Q.empty())
        {
            int k = Q.front();
            Q.pop();
            for (int s : G[k])
                if (D[s] == -1)
                    D[s] = D[k] + 1, Q.push(s);
        }
        for (int i = 1; i < p; ++i)
            cout << D[i] << '\n';
        if (t) cout << '\n';
    }
}
