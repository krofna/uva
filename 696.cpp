#include <iostream>
using namespace std;

int main()
{
    int a, b;
    while (cin >> a >> b, a || b)
    {
        int c = min(a, b), d = max(a, b), e = (a * b + 1) / 2, g = 4 * (d / 4);
        if (c == 2)
        {
            switch (d % 4)
            {
            case 0: e = g; break;
            case 1: e = g + 2; break;
            case 2: e = g + 4; break;
            case 3: e = g + 4; break;
            }
        }
        cout << (c == 1 ? d : e) << " knights may be placed on a " << a << " row " << b << " column board.\n";
    }
}
