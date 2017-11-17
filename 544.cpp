#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>
#include <tuple>
#include <limits>
using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef priority_queue<ii> pqii;
typedef vector<bool> vb;
typedef vector<vii> vvii;

void p(pqii& Q, vvii& G, vb& T, int x)
{
    T[x] = true;
    for (auto& p : G[x])
        if (!T[p.second])
            Q.push(p);
}

int main()
{
    int n, r, w, x, y, t = 1;
    while (cin >> n >> r, n || r)
    {
        unordered_map<string, int> M;
        string a, b;
        int k = 0;
        vvii G(n);
        for (int i = 0; i < r; ++i)
        {
            cin >> a >> b >> w;
            auto p = M.emplace(a, k);
            if (p.second) k++;
            auto q = M.emplace(b, k);
            if (q.second) k++;
            x = p.first->second;
            y = q.first->second;
            G[x].emplace_back(w, y);
            G[y].emplace_back(w, x);
        }
        cin >> a >> b;
        pqii Q;
        vb T(n, false);
        p(Q, G, T, M[a]);
        y = M[b];
        int c = numeric_limits<int>::max();
        while (!Q.empty())
        {
            tie(w, x) = Q.top(); Q.pop();
            if (!T[x])
                c = min(c, w), p(Q, G, T, x);
            if (x == y)
                break;
        }
        cout << "Scenario #" << t++ << '\n';
        cout << c << " tons\n\n";
    }
}
