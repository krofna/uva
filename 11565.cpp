#include <iostream>
#include <cmath>
using namespace std;

int n, a, b, c;

inline bool f(int x, int y)
{
    int z = a - x - y;
    if (x * y * z == b && x * x + y * y + z * z == c && x != y && y != z && x != z)
    {
        cout << x << " " << y << " " << z << '\n';
        return true;
    }
    return false;
}

int main()
{
    cin >> n;
    while (n--)
    {
        cin >> a >> b >> c;
        int q = min(b, (int)sqrt(c));
        for (int x = -q; x < q; ++x)
        {
            if (!x || b % x) continue;
            for (int y = -q; y <= q; ++y)
                if (f(x, y))
                    goto done;
        }
        cout << "No solution.\n";
    done:
        ;
    }
}
