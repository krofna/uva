#include <iostream>
using namespace std;

int f(int n)
{
    int m = 0;
    while (n)
    {
        m += n % 10;
        n /= 10;
    }
    return m;
}

int main()
{
    int n;
    while (cin >> n, n)
    {
        while (n >= 10)
            n = f(n);
        cout << n << '\n';
    }
}
