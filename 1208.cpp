#include <iostream>
#include <vector>
#include <tuple>
#include <queue>
#include <sstream>
using namespace std;

typedef tuple<int, int, int> iii;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<vii> vvii;
typedef vector<iii> viii;
typedef greater<iii> giii;
typedef priority_queue<iii, viii, giii> pqiii;
typedef vector<bool> vb;

void p(pqiii& Q, vvii& G, vb& T, int x)
{
    T[x] = true;
    for (int i = 0; i < G[x].size(); ++i)
        if (!T[G[x][i].second])
            Q.emplace(G[x][i].first, G[x][i].second, x);
}

int main()
{
    int t, n, x, y, w;
    cin >> t;
    for (int z = 1; z <= t; ++z)
    {
        cout << "Case " << z << ":\n";
        cin >> n;
        cin.ignore();
        vvii G(n, vii());
        for (int i = 0; i < n; ++i)
        {
            string s;
            getline(cin, s);
            istringstream iss(s);
            for (int j = 0; j < n; ++j)
            {
                getline(iss, s, ',');
                if (w = stoi(s))
                    G[i].emplace_back(w, j);
            }
        }
        pqiii Q, R;
        vb T(n, false);
        p(Q, G, T, 0);
        while (!Q.empty())
        {
            tie(w, x, y) = Q.top(); Q.pop();
            if (!T[x])
            {
                R.emplace(w, x, y);
                p(Q, G, T, x);
            }
        }
        // TODO: Trebo sam kruskal...
        while (!R.empty())
        {
            tie(w, x, y) = R.top(); R.pop();
            cout << char('A' + min(x, y)) << '-';
            cout << char('A' + max(x, y)) << ' ' << w << '\n';
        }
    }
}
