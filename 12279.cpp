#include <iostream>
using namespace std;

const int d[] = { -1, 1 };

int main()
{
    int n, u = 1, b, k;
    while (cin >> n, n)
    {
        b = 0;
        for (int i = 0; i < n; ++i)
        {
            cin >> k;
            b += d[bool(k)];
        }
        cout << "Case " << u++ << ": " << b << '\n';
    }
}
