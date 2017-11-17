#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

struct point
{
    double x, y;
    point()
    {
    }
    point(double x, double y) : x(x), y(y)
    {
    }
    friend istream& operator>>(istream& i, point& p)
    {
        return i >> p.x >> p.y;
    }
    friend ostream& operator<<(ostream& o, point p)
    {
        return o << p.x << " " << p.y;
    }
};

struct line
{
    double k, l;
    line(point& p1, point& p2)
    {
        k = (p2.y - p1.y) / (p2.x - p1.x), l = p1.y - k * p1.x;
    }
};

bool eq(double a, double b)
{
    return fabs(a - b) < 1e-8;
}

point ip(line& l1, line& l2)
{
    double x = (l2.l - l1.l) / (l1.k - l2.k);
    double y = l1.k * x + l1.l;
    return point(x, y);
}

point ip(line l, double x)
{
    return point(x, l.k * x + l.l);
}

bool vl(point& p1, point& p2, point& q1, point& q2)
{
    if (p1.x != p2.x)
        return false;

    if (q1.x == q2.x)
    {
        if (p1.x == q1.x)
            cout << "LINE\n";
        else
            cout << "NONE\n";
    }
    else
        cout << "POINT " << fixed << setprecision(2) << ip(line(q1, q2), p1.x) << '\n';
    return true;
}

int main()
{
    int n;
    cin >> n;
    cout << "INTERSECTING LINES OUTPUT\n";
    for (int i = 0; i < n; ++i)
    {
        point p1, p2, q1, q2;
        cin >> p1 >> p2 >> q1 >> q2;
        if (vl(p1, p2, q1, q2) || vl(q1, q2, p1, p2))
            continue;
        
        line l1(p1, p2), l2(q1, q2);
        if (eq(l1.k, l2.k))
        {
            if (eq(l1.l, l2.l))
                cout << "LINE\n";
            else
                cout << "NONE\n";
        }
        else
            cout << "POINT " << fixed << setprecision(2) << ip(l1, l2) << '\n';
    }
    cout << "END OF OUTPUT\n";
}
