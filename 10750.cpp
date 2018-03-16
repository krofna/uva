#include <iostream>
#include <set>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

#define inf 1e9

struct point
{
    double x, y;
    point(){}
    point(double x, double y) : x(x), y(y) {}
    bool operator < (const point& b) const { return y < b.y;} 
};

bool cmpx(point& a, point& b) { return a.x < b.x;}

vector<point> P;
int n;

point ClosestPoints()
{
    set<point> box;
    sort(P.begin(), P.end(), cmpx);
    double best = inf;
    point bestp;
    box.insert(P[0]);
    int left = 0;
    for (int i = 1; i < n; ++i)
    {
        while (left < i && P[i].x - P[left].x > best)
            box.erase(P[left++]);
        point B(P[i].x - best, P[i].y - best);
        for (auto it = box.lower_bound(B); it != box.end() && P[i].y + best >= it->y; ++it)
        {
            double dst = hypot(P[i].y - it->y, P[i].x - it->x);
            if (dst < best)
            {
                best = min(best, dst);
                bestp = *it;
            }
        }
        box.insert(P[i]);
    }
    return bestp;
}

int main()
{
    int f;
    ios::sync_with_stdio(false);
    cin >> f;
    while (f--)
    {
        cin >> n;
        P.assign(n, point()); 
        for (int i = 0; i < n; ++i)
            cin >> P[i].x >> P[i].y;

        point bestp = ClosestPoints();
        cout << bestp.x << " " << bestp.y << '\n';
        if (f) cout << '\n';
    }
}
