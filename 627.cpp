#include <iostream>
#include <algorithm>
#include <sstream>
#include <vector>
#include <queue>
using namespace std;

void print(vector<int>& P, int b, bool& f)
{
    if (P[b] != b)
        print(P, P[b], f);
    if (!f) f = true;
    else cout << ' ';
    cout << b + 1;
}

int main()
{
    int n;
    while (cin >> n)
    {
        cin.ignore();
        cout << "-----\n";
        vector<vector<int> > G(n);
        for (int i = 0; i < n; ++i)
        {
            string s;
            getline(cin, s);
            string z = s.substr(s.find('-') + 1);
            replace(z.begin(), z.end(), ',', ' ');
            istringstream iss(z);
            int k;
            while (iss >> k)
                G[i].push_back(k - 1);
        }
        int m;
        cin >> m;
        for (int i = 0; i < m; ++i)
        {
            int a, b;
            cin >> a >> b;
            a -= 1, b -= 1;
            queue<int> Q;
            Q.push(a);
            vector<int> P(n, -1);
            P[a] = a;
            while (!Q.empty())
            {
                int k = Q.front();
                Q.pop();
                for (int s : G[k])
                    if (P[s] == -1)
                        P[s] = k, Q.push(s);
            }
            if (P[b] != -1)
            {
                bool f = false;
                print(P, b, f);
            }
            else
                cout << "connection impossible";
            cout << '\n';
        }
    }
}
