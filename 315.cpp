#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

int n, m, k, c, rc, r;

void dfs(vvi& G, vi& N, vi& L, vi& P, vi& A, int u)
{
    L[u] = N[u] = c++;
    for (int v : G[u])
    {
        if (N[v] == -1)
        {
            P[v] = u;
            if (u == r) rc++;

            dfs(G, N, L, P, A, v);

            if (L[v] >= N[u])
                A[u] = true;
            L[u] = min(L[u], L[v]);
        }
        else if (v != P[u])
            L[u] = min(L[u], N[v]);
    }
}

int main()
{
    while (cin >> n, n)
    {
        vvi G(n, vi());
        while (cin >> m, m)
        {
            string s;
            getline(cin, s);
            istringstream iss(s);
            while (iss >> k)
            {
                G[m - 1].push_back(k - 1);
                G[k - 1].push_back(m - 1);
            }
        }
        vi N(n, -1), L(n, -1), P(n, -1), A(n, false);
        c = 0;
        for (int i = 0; i < n; ++i)
        {
            if (N[i] == -1)
            {
                r = i;
                rc = 0;
                dfs(G, N, L, P, A, i);
                A[r] = (rc > 1);
            }
        }
        cout << count(A.begin(), A.end(), true) << '\n';
    }
}
