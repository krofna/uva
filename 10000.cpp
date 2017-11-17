#include <iostream>
#include <vector>
#include <stack>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

stack<int> S;

void dfs(vvi& G, bool T[100], int x)
{
    T[x] = true;
    for (int i : G[x])
        if (!T[i])
            dfs(G, T, i);
    S.push(x);
}

int main()
{
    ios::sync_with_stdio(false);
    int n, s, p, q, t = 1;
    while (cin >> n, n)
    {
        cin >> s; s--;
        vvi G(n, vi());
        while (cin >> p >> q, p || q)
        {
            p--; q--;
            G[p].push_back(q);
        }
        bool T[100] = {};
        int D[100] = {};
        dfs(G, T, s);
        int l = 0; q = 100;
        while (!S.empty())
        {
            p = S.top(); S.pop();
            for (int i : G[p])
            {
                if (D[p] + 1 > D[i])
                {
                    D[i] = D[p] + 1;
                    if (D[i] == l)
                        q = min(q, i);
                    
                    if (D[i] > l)
                    {
                        l = D[i];
                        q = i;
                    }
                }
            }
        }
        cout << "Case " << t++ << ": ";
        cout << "The longest path from " << s + 1;
        cout << " has length " << l;
        cout << ", finishing at " << q + 1 << ".\n\n";
    }
}
