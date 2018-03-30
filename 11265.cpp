#include <vector>
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

#define eps 1e-9

struct point
{
    double x, y;
    point() {}
    point(double x, double y) : x(x), y(y) {}
    bool operator < (point& b) {return x < b.x || (x == b.x && y < b.y);}
    friend istream& operator >>(istream& in, point& p) {return in >> p.x >> p.y;}
};

double dot(point a, point b)
{
    return a.x * b.x + a.y * b.y;
}

double angle(point a, point o, point b)
{
    point a_p = point(a.x - o.x, a.y - o.y), b_p = point(b.x - o.x, b.y - o.y);
    return acos(dot(a_p, b_p) / sqrt(dot(a_p, a_p) * dot(b_p, b_p)));
}

double cross(point a, point o, point b)
{
    return (a.x - o.x) * (b.y - o.y) - (a.y - o.y) * (b.x - o.x);
}

point lineIntersectSeg(point& p, point& q, point& A, point& B)
{
    double a = B.y - A.y;
    double b = A.x - B.x;
    double c = B.x * A.y - A.x * B.y;
    double u = abs(a * p.x + b * p.y + c);
    double v = abs(a * q.x + b * q.y + c);
    return point((p.x * v + q.x * u) / (u + v), (p.y * v + q.y * u) / (u + v));
}

vector<point> cutPolygon(point& a, point& b, vector<point>& Q)
{
    vector<point> P;
    for (int i = 0; i < Q.size(); ++i)
    {
        double left1 = cross(b, Q[i], a), left2 = 0;
        if (i != Q.size() - 1)
            left2 = cross(b, Q[i + 1], a);

        if (left1 > -eps)
            P.push_back(Q[i]);

        if (left1 * left2 < -eps)
            P.push_back(lineIntersectSeg(Q[i], Q[i + 1], a, b));
    }

    if (!P.empty() && !(P.back().x == P.front().x && P.back().y == P.front().y))
        P.push_back(P.front());

    return P;
}

bool InPolygon(point& p, const vector<point>& P)
{
    double sum = 0;
    for (int i = 0; i < (int)P.size() - 1; ++i)
    {
        if (cross(P[i], p, P[i + 1]) > 0)
            sum += angle(P[i], p, P[i + 1]);
        else
            sum -= angle(P[i], p, P[i + 1]);
    }
    return abs(abs(sum) - 2 * M_PI) < eps;
}

double Area(vector<point>& P)
{
    if (P.size() < 3)
        return 0;
    double A = 0;
    for (int i = 0; i < P.size() - 1; ++i)
    {
        double x1 = P[i].x, x2 = P[i + 1].x;
        double y1 = P[i].y, y2 = P[i + 1].y;
        A += (x1 * y2 - x2 * y1);
    }    
    return 0.5 * abs(A);
}

int main()
{
    double w, h, x, y;
    point a, b, c;
    int n, t = 1;
    ios::sync_with_stdio(false);
    while (cin >> n >> w >> h >> c)
    {
        vector<point> Q = {{0, 0}, {w, 0}, {w, h}, {0, h}, {0, 0}};
        for (int i = 0; i < n; ++i)
        {
            cin >> a >> b;
            vector<point> P = cutPolygon(a, b, Q);
            if (InPolygon(c, P))
                Q = P;
            else
                Q = cutPolygon(b, a, Q);
        }
        cout << "Case #" << t++ << ": " << fixed << setprecision(3) << Area(Q) << '\n';
    }
}
