#include <iostream>
#include <vector>
using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<vii> vvii;
typedef vector<int> vi;

int main()
{
    ios::sync_with_stdio(false);
    int c, n, m, x, y, t;
    cin >> c;
    while (c--)
    {
        cin >> n >> m;
        vvii G(n, vii());
        for (int i = 0; i < m; ++i)
        {
            cin >> x >> y >> t;
            G[x].emplace_back(y, t);
        }

        vi D(n, 1000);
        for (int i = 0; i < n - 1; ++i)
            for (int j = 0; j < n; ++j)                
                for (auto p : G[j])
                    D[p.first] = min(D[p.first], D[j] + p.second);

        bool pos = false;
        for (int i = 0; i < n && !pos; ++i)
            for (auto p : G[i])
                if (D[p.first] > D[i] + p.second)
                    pos = true;

        if (pos)
            cout << "possible\n";
        else
            cout << "not possible\n";
    }
}
