#include <iostream>
using namespace std;

int main()
{
    int n;
    while (cin >> n, n)
    {
        int a[2] = {0}, f = 0;
        for (unsigned i = 1; i <= (1 << 30); i <<= 1)
            if (n & i)
                a[f++ % 2] |= i;
        cout << a[0] << ' ' << a[1] << '\n';
    }
}
