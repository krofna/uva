#include <iostream>
using namespace std;

int main()
{
    int a, b, c;
    while (cin >> a >> b >> c, a || b || c)
    {
        if (a > c) swap(a, c);
        if (b > c) swap(b, c);
        cout << ((a * a + b * b == c * c) ? "right\n" : "wrong\n");
    }
}
