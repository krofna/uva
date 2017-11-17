#include <iostream>
using namespace std;

int main()
{
    long long n, p;
    while (cin >> n >> p, n || p)
    {
        long long v = 1, h = 1, s = 1, x = n / 2 + 1, y = n / 2 + 1, i;
        for (i = 0; s < p; ++i)
        {
            switch (i % 4)
            {
            case 0: y += v; s += v++; if (s > p) y -= s - p; break;
            case 1: x -= h; s += h++; if (s > p) x += s - p; break;
            case 2: y -= v; s += v++; if (s > p) y += s - p; break;
            case 3: x += h; s += h++; if (s > p) x -= s - p; break;
            }
        }
        cout << "Line = " << y << ", column = " << x << ".\n";
    }
}
