#include <iostream>
#include <vector>
#include <utility>
#include <tuple>
#include <algorithm>
#include <queue>
#include <iomanip>
using namespace std;

#define INF 1000000000
typedef pair<int, int> ii;

int main()
{
    int n, m, a, b, l, v, w, vv, ww, t = 1;
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(1);
    while (cin >> n >> m, n || m)
    {
        vector<vector<ii> > G(n);
        for (int i = 0; i < m; ++i)
        {
            cin >> a >> b >> l;
            G[a - 1].emplace_back(b - 1, l);
            G[b - 1].emplace_back(a - 1, l);
        }
        priority_queue<ii, vector<ii>, greater<ii> > PQ;
        vector<int> D(n, INF);
        PQ.emplace(0, 0);
        D[0] = 0;
        while (!PQ.empty())
        {
            tie(w, v) = PQ.top(); PQ.pop();
            if (w > D[v])
                continue;

            for (int i = 0; i < G[v].size(); ++i)
            {
                tie(vv, ww) = G[v][i];
                if (D[v] + ww < D[vv])
                {
                    D[vv] = D[v] + ww;
                    PQ.emplace(D[vv], vv);
                }
            }
        }
        bool flg = false;
        float mx = 0;
        int b1 = 0, b2 = 0;
        for (int i = 1; i < n; ++i)
        {
            if (D[i] > mx)
            {
                mx = D[i];
                b1 = i;
                flg = false;
            }
            for (int j = 0; j < G[i].size(); ++j)
            {
                tie(vv, ww) = G[i][j];
                if (D[vv] + ww > D[i] && D[i] + ww != D[vv])
                {
                    float nmx = D[i] + float(ww - (D[i] - D[vv])) / 2.f;
                    if (nmx > mx)
                    {
                        mx = nmx;
                        tie(b1, b2) = minmax(i, vv);
                        flg = true;
                    }
                }
            }
        }
        cout << "System #" << t++ << '\n';
        cout << "The last domino falls after " << mx << " seconds, ";
        if (flg)
            cout << "between key dominoes " << b1 + 1 << " and " << b2 + 1 << ".\n\n";
        else
            cout << "at key domino " << b1 + 1 << ".\n\n";
    }
}
