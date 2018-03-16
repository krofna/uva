#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <iomanip>
using namespace std;

struct point
{
    double x, y;
    point() {}
    point(double x, double y) : x(x), y(y) {}
    bool operator == (point& b) const {return x == b.x && y == b.y;}
    bool operator < (point& b) {return x < b.x || (x == b.x && y < b.y);}
    friend istream& operator >>(istream& in, point& p) {return in >> p.x >> p.y;}
};

double cross(point a, point b, point o)
{
    return (a.x - o.x) * (b.y - o.y) - (a.y - o.y) * (b.x - o.x);
}

bool ccw(point p, point q, point r)
{
    return cross(q, r, p) >= 0;
}

vector<point> ConvexHull(vector<point>& P)
{
    int n = P.size(), k = 0;
    sort(P.begin(), P.end());
    vector<point> H(2 * n);
    for (int i = 0; i < n; ++i)
    {
        while (k >= 2 && !ccw(H[k - 2], H[k - 1], P[i]))
            k--;
        H[k++] = P[i];
    }

    for (int i = n - 2, t = k + 1; i >= 0; --i)
    {
        while (k >= t && !ccw(H[k - 2], H[k - 1], P[i]))
            k--;
        H[k++] = P[i];
    }

    H.resize(k);
    return H;
}

double dst(point a, point b, point c)
{
    double A = b.y - a.y;
    double B = b.x - a.x;
    return abs(A * c.x - B * c.y + b.x * a.y - b.y * a.x) / hypot(A, B);
}

int main()
{
    ios::sync_with_stdio(false);
    int n, t = 1;
    while (cin >> n, n)
    {
        vector<point> P(n);
        for (int i = 0; i < n; ++i)
            cin >> P[i];

        P = ConvexHull(P);
        double mn = 1e9;
        for (int i = 1; i < P.size(); ++i)
        {
            double mx = 0;
            for (int j = 1; j < P.size(); ++j)
                mx = max(mx, dst(P[i - 1], P[i], P[j]));
            mn = min(mn, mx);
        }
        cout << "Case " << t++ << ": " << setprecision(2) << fixed << mn << '\n';
    }
}
