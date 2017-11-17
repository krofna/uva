#include <iostream>
#include <vector>
#include <stack>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<bool> vb;

stack<int> S;

void topsort(vvi& G, vb& B, int x)
{
    B[x] = true;
    for (int k : G[x])
        if (!B[k])
            topsort(G, B, k);
    S.push(x);
}

int main()
{
    int m, n = -1, k;
    while (cin >> m)
    {
        if (n != -1) cout << '\n';
        vvi G(m, vi());
        for (int i = 0; i < m; ++i)
        {
            cin >> n;
            G[i].resize(n);
            for (int j = 0; j < n; ++j)
            {
                cin >> k;
                G[i][j] = k;
            }
        }
        vb B(m, false);
        topsort(G, B, 0);
        vi C(m, 0);
        C[0] = 1;
        int cnt = 0;
        while (!S.empty())
        {
            k = S.top(); S.pop();
            for (int x : G[k])
                C[x] += C[k];
            if (G[k].empty())
                cnt += C[k];
        }
        cout << cnt << '\n';
    }
}
