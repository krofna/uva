#include <iostream>
#include <vector>
#include <tuple>
#include <queue>
#include <algorithm>
#include <limits>
using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vii> vvii;

int main()
{
    int n, e, t, m, l, a, b, w, ww;
    cin >> l;
    while (l--)
    {
        cin >> n >> e >> t >> m;
        vvii G(n);
        for (int i = 0; i < m; ++i)
        {
            cin >> a >> b >> w;
            G[b - 1].emplace_back(a - 1, w);
        }
        priority_queue<ii, vii, greater<ii>> Q;
        Q.emplace(0, e - 1);
        vi D(n, 10000000);
        D[e - 1] = 0;
        while (!Q.empty())
        {
            tie(w, a) = Q.top(); Q.pop();
            if (w > D[a])
                continue;

            for (int i = 0; i < G[a].size(); ++i)
            {
                tie(b, ww) = G[a][i];
                if (D[a] + ww < D[b])
                {
                    D[b] = D[a] + ww;
                    Q.emplace(D[b], b);
                }
            }
        }
        cout << count_if(D.begin(), D.end(), [t](int x){return x <= t;}) << '\n';
        if (l) cout << '\n';
    }
}
