#include <iostream>
#include <map>
#include <queue>
using namespace std;

string A[100];
map<string, int> M;
vector<int> G[100];
int D[100];

int main()
{
    int n, m, t = 1;
    while (cin >> n)
    {
        M.clear();
        for (int i = 0; i < n; ++i)
        {
            cin >> A[i];
            M[A[i]] = i;
            G[i].clear();
            D[i] = 0;
        }
        cin >> m;
        string a, b;
        for (int i = 0; i < m; ++i)
        {
            cin >> a >> b;
            int ma = M[a], mb = M[b];
            G[ma].push_back(mb);
            D[mb]++;
        }
        priority_queue<int, vector<int>, greater<int> > Q;
        for (int i = 0; i < n; ++i)
            if (D[i] == 0)
                Q.push(i);

        cout << "Case #" << t++;
        cout << ": Dilbert should drink beverages in this order:";
        while (!Q.empty())
        {
            int k = Q.top(); Q.pop();
            cout << ' ' << A[k];
            for (int i = 0; i < G[k].size(); ++i)
                if (--D[G[k][i]] == 0)
                    Q.push(G[k][i]);
        }
        cout << ".\n\n";
    }
}
    
