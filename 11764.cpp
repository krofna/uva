#include <iostream>
using namespace std;

int main()
{
    int t, u = 1;
    cin >> t;
    while (t--)
    {
        int l = 0, h = 0, p, c, n;
        cin >> n;
        cin >> p;
        while (--n)
        {
            cin >> c;
            if (c > p) ++h;
            if (c < p) ++l;
            p = c;
        }
        cout << "Case " << u++ << ": " << h << ' ' << l << '\n';
    }
}
