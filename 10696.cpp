#include <iostream>
using namespace std;

int f(int n)
{
    return n <= 100 ? f(f(n + 11)) : n - 10;
}

int main()
{
    int n;
    while (cin >> n, n)
        cout << "f91(" << n << ") = " << f(n) << '\n';
}

