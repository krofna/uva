#include <iostream>
#include <map>
#include <vector>
#include <queue>
using namespace std;

void print(map<string, string>& P, string& b)
{
    if (P[b] != b)
        print(P, P[b]);
    cout << b.front();
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int m, n;
        string a, b;
        cin >> m >> n;
        map<string, vector<string> > M;
        for (int i = 0; i < m; ++i)
        {
            cin >> a >> b;
            M[a].push_back(b);
            M[b].push_back(a);
        }
        for (int i = 0; i < n; ++i)
        {
            cin >> a >> b;
            queue<string> Q;
            Q.push(a);
            map<string, string> P;
            P[a] = a;
            while (!Q.empty())
            {
                string k = Q.front();
                Q.pop();
                for (string s : M[k])
                    if (P[s].empty())
                        P[s] = k, Q.push(s);
            }
            print(P, b);
            cout << '\n';
        }
        if (t) cout << '\n';
    }
}
