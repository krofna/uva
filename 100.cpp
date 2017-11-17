#include <iostream>
using namespace std;

int f(int n)
{
    if (n == 1)
        return 1;

    return n % 2 ? 3 * n + 1 : n / 2;
}

int main()
{
    int a, b;
    while (cin >> a >> b)
    {
        int max = 1;
        for (int i = min(a, b); i <= ::max(a, b); ++i)
        {
            int len = 2, n = i;
            if (i == 1) len = 1;
            while (n = f(n), n != 1) ++len;
            max = ::max(max, len);
        }
        cout << a << ' ' << b << ' ' << max << '\n';
    }
}
