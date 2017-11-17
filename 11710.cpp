#include <iostream>
#include <unordered_map>
#include <queue>
#include <vector>
using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef greater<ii> gii;
typedef vector<vii> vvii;
typedef priority_queue<ii, vii, gii> pqii;
typedef vector<bool> vb;

void p(pqii& Q, vvii& G, vb& T, int x)
{
    T[x] = true;
    for (int i = 0; i < G[x].size(); ++i)
        if (!T[G[x][i].second])
            Q.push(G[x][i]);
}

int main()
{
    ios::sync_with_stdio(false);
    int s, c, w, x, y;
    while (cin >> s >> c, s || c)
    {
        unordered_map<string, int> M;
        for (int i = 0; i < s; ++i)
        {
            string a;
            cin >> a;
            M[a] = i;
        }
        vvii G(s, vii());
        string a, b;
        for (int i = 0; i < c; ++i)
        {
            cin >> a >> b >> w;
            x = M[a];
            y = M[b];
            G[x].emplace_back(w, y);
            G[y].emplace_back(w, x);
        }
        cin >> a;
        vb T(s, false);
        pqii Q;
        p(Q, G, T, 0);
        int k = 1, ww = 0;
        while (!Q.empty())
        {
            tie(w, x) = Q.top(); Q.pop();
            if (!T[x])
                k++, ww += w, p(Q, G, T, x);
        }
        if (k == s)
            cout << ww << '\n';
        else
            cout << "Impossible\n";
    }
}
