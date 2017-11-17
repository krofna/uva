#include <iostream>
using namespace std;

int main()
{
    int a, c, x, y;
    while (cin >> a >> c, a)
    {
        cin >> y;
        int s = a - y;
        for (int i = 1; i < c; ++i)
        {
            cin >> x;
            if (x < y)
                s += y - x;
            y = x;
        }
        cout << s << '\n';
    }
}
