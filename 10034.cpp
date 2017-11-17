#include <iostream>
#include <queue>
#include <iomanip>
#include <cmath>
#include <tuple>
using namespace std;

typedef pair<float, float> ff;
typedef vector<ff> vff;
typedef pair<float, int> fi;
typedef vector<fi> vfi;
typedef greater<fi> gfi;
typedef priority_queue<fi, vfi, gfi> pqfi;
typedef vector<bool> vb;

void p(pqfi& Q, vff& V, vb& T, int j)
{
    T[j] = true;
    for (int i = 0; i < V.size(); ++i)
        if (!T[i])
            Q.emplace(hypot(V[i].first - V[j].first, V[i].second - V[j].second), i);
}

int main()
{
    int t, n, j;
    float x, y, w;
    cin >> t;
    while (t--)
    {
        cin >> n;
        vff V;
        for (int i = 0; i < n; ++i)
        {
            cin >> x >> y;
            V.emplace_back(x, y);
        }
        vb T(n, false);
        pqfi Q;
        p(Q, V, T, 0);
        float d = 0.f;
        while (!Q.empty())
        {
            tie(w, j) = Q.top(); Q.pop();
            if (!T[j])
                d += w, p(Q, V, T, j);
        }
        cout << fixed << setprecision(2) << d << '\n';
        if (t) cout << '\n';
    }
}
