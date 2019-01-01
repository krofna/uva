#include <iostream>
#include <map>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

int main()
{
    int k;
    bool f = false;
    while (cin >> k)
    {
        if (f) cout << '\n';
        f = true;
        cin.ignore();
        string a, b;
        map<string, vector<string> > M;
        for (int i = 0; i < k; ++i)
        {
            cin >> a >> b;
            M[a].push_back(b);
            M[b].push_back(a);
        }
        cin >> a >> b;
        queue<string> Q;
        map<string, string> P;
        Q.push(a);
        P[a] = a;
        while (!Q.empty())
        {
            string k = Q.front();
            Q.pop();
            for (string s : M[k])
                if (P[s].empty())
                    P[s] = k, Q.push(s);
        }
        if (!P[b].empty())
        {
            stack<string> S;
            for (string k = b; k != a; k = P[k])
                S.push(k);

            while (!S.empty())
            {
                cout << a << ' ' << S.top() << '\n';
                a = S.top();
                S.pop();
            }
        }
        else
            cout << "No route\n";
    }
}
