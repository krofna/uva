#include <iostream>
using namespace std;

int main()
{
    int r, n, u = 1;
    while (cin >> r >> n, r + n)
    {
        int x = r > n ? (r - n - 1) / n + 1 : 0;
        cout << "Case " << u++ << ": ";
        if (x <= 26)
            cout << x << '\n';
        else
            cout << "impossible\n";
    }
}
