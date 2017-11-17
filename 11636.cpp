#include <iostream>
using namespace std;

int main()
{
    int n, u = 1;
    while (cin >> n, n > 0)
    {
        cout << "Case " << u++ << ": ";
        if (__builtin_popcount(n) == 1)
            cout << __builtin_ctz(n) << '\n';
        else
            cout << 8 * sizeof(int) - __builtin_clz(n) << '\n';
    }
}
