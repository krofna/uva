#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <cmath>
#include <iomanip>
using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef greater<ii> gii;
typedef priority_queue<ii, vii, gii> pqii;
typedef vector<bool> vb;

int sq(int i)
{
    return i * i;
}

int dist(vii& V, int i, int j)
{
    return sq(V[i].first - V[j].first) + sq(V[i].second - V[j].second);
}

void p(pqii& Q, vii& V, vb& T, int x)
{
    T[x] = true;
    for (int i = 0; i < V.size(); ++i)
        if (!T[i])
            Q.emplace(dist(V, x, i), i);
}

int main()
{
    int n, x, y, w, t = 1;
    cout << fixed << setprecision(3);
    while (cin >> n, n)
    {
        vii V;
        for (int i = 0; i < n; ++i)
        {
            cin >> x >> y;
            V.emplace_back(x, y);
        }
        pqii Q;
        vb T(n, false);
        p(Q, V, T, 0);
        int k = 0;
        while (!Q.empty())
        {
            tie(w, x) = Q.top(); Q.pop();
            if (!T[x])
                k = max(k, w), p(Q, V, T, x);
            if (x == 1)
                break;
        }
        cout << "Scenario #" << t++ << '\n';
        cout << "Frog Distance = " << sqrt(k) << "\n\n";
    }
}
