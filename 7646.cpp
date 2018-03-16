#include <iostream>
using namespace std;

int main()
{
    int d, r, t;
    while (cin >> d >> r >> t)
    {
        for (int i = 3; i < 1000; ++i)
        {
            int q = (i * (i + 1)) / 2 - 3 - t;
            int p = r - (i + d) * (i + d + 1) / 2 + 6;
            if (p == q)
                cout << p << '\n';
        }
    }
}
