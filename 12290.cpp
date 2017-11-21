#include <iostream>
using namespace std;

bool f(int c)
{
    if (c % 7 == 0)
        return true;
    while (c)
    {
        if (c % 10 == 7)
            return true;
        c /= 10;
    }
    return false;
}

int main()
{
    int n, m, k;
    while (cin >> n >> m >> k, n || m || k)
    {
        int d = 1, q = 0;
        while (true)
        {
            for (int i = 1; i <= n; ++i, ++d)
                if (i == m && f(d))
                    if (++q == k) goto brk;
            for (int i = n - 1; i > 1; --i, ++d)
                if (i == m && f(d))
                    if (++q == k) goto brk;
        }
    brk: cout << d << '\n';
    }
}
