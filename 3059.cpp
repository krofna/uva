#include <iostream>
using namespace std;

int main()
{
    int n;
    while (cin >> n, n != -1)
    {
        int a, b, c, d;
        cin >> a >> b;
        c = a * b;
        for (int i = 1; i < n; ++i)
            cin >> a >> d, c += (d - b) * a, b = d;
        cout << c << " miles\n";
    }
}
