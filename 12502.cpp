#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int x, y, z;
        cin >> x >> y >> z;
        x *= 60, y *= 60;
        cout << max(0, x - (x + y) / 3) * z * 3 / (x + y) << '\n';
    }
}
