#include <iostream>
#include <queue>
#include <vector>
#include <tuple>
#include <limits>
using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

int main()
{
    ios_base::sync_with_stdio(false);
    int N, n, m, S, T, a, b, w, ww;
    cin >> N;
    for (int i = 1; i <= N; ++i)
    {
        cin >> n >> m >> S >> T;
        vector<vii> G(n);
        for (int j = 0; j < m; ++j)
        {
            cin >> a >> b >> w;
            G[a].emplace_back(b, w);
            G[b].emplace_back(a, w);
        }
        priority_queue<ii, vii, greater<ii>> Q;
        vi D(n, numeric_limits<int>::max());
        D[S] = 0;
        Q.emplace(0, S);
        while (!Q.empty())
        {
            tie(w, a) = Q.top(); Q.pop();
            if (w > D[a])
                continue;

            if (a == T)
                break;
            
            for (int j = 0; j < G[a].size(); ++j)
            {
                tie(b, ww) = G[a][j];
                if (D[a] + ww < D[b])
                {
                    D[b] = D[a] + ww;
                    Q.emplace(D[b], b);
                }
            }
        }
        cout << "Case #" << i << ": ";
        if (a == T)
            cout << D[T] << '\n';
        else
            cout << "unreachable\n";
    }
}
