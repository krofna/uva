#include <iostream>
using namespace std;

int main()
{
    int a, b, c, d, l;
    while (cin >> a >> b >> c >> d >> l, a || b || c || d || l)
    {
        int k = 0;
        for (int i = 0; i <= l; ++i)
            if ((a * i * i + b * i + c) % d == 0)
                ++k;
        cout << k << '\n';
    }
}
