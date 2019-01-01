#include <iostream>
#include <sstream>
#include <vector>
#include <tuple>
#include <queue>
#include <functional>
#include <limits>
#include <cmath>
#include <iomanip>
using namespace std;

#define INF numeric_limits<double>::max()

typedef pair<double, int> di;
typedef priority_queue<di, vector<di>, greater<di> > pdi;

struct point
{
    double x, y;
    friend istream& operator>>(istream& i, point& p)
    {
        return i >> p.x >> p.y;
    }
};

double dist(const point& p1, const point& p2, double v)
{
    return hypot(p2.x - p1.x, p2.y - p1.y) / (v * 1000.) * 60.;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        vector<point> P(2);
        cin >> P[0] >> P[1];
        cin.ignore();
        vector<vector<int> > G(2);
        G[0].push_back(1);
        vector<vector<double> > D;
        D.assign(202, vector<double>(202, INF));
        D[0][1] = dist(P[0], P[1], 10);
        string s;
        while (getline(cin, s), cin && !s.empty())
        {
            int sz = P.size();
            istringstream iss(s);
            double x, y;
            while (iss >> x >> y, x >= 0)
                P.push_back({x, y});

            G.resize(P.size());
            for (int i = sz; i < P.size(); ++i)
            {
                G[0].push_back(i);
                G[i].push_back(1);
                D[0][i] = dist(P[0], P[i], 10);
                D[i][1] = dist(P[i], P[1], 10);
                if (i != sz)
                {
                    G[i - 1].push_back(i);
                    G[i].push_back(i - 1);
                    D[i - 1][i] = D[i][i - 1] = dist(P[i - 1], P[i], 40);
                }
            }
        }
        for (int i = 2; i < P.size(); ++i)
        {
            for (int j = 2; j < P.size(); ++j)
            {
                if (i != j && D[i][j] == INF)
                {
                    G[i].push_back(j);
                    G[j].push_back(i);
                    D[i][j] = dist(P[i], P[j], 10);
                }
            }
        }

        pdi Q;
        vector<double> B(D.size(), INF);
        B[0] = 0;
        Q.emplace(0, 0);
        while (!Q.empty())
        {
            double d;
            int k;
            tie(d, k) = Q.top(); Q.pop();
            if (d > B[k])
                continue;

            if (k == 1)
                break;

            for (int kk : G[k])
            {
                if (B[k] + D[k][kk] < B[kk])
                {
                    B[kk] = B[k] + D[k][kk];
                    Q.emplace(B[kk], kk);
                }
            }
        }
        cout << fixed << setprecision(0) << B[1] << '\n';
        if (t) cout << '\n';
    }
}
