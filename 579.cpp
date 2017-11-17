#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main()
{
    int h, m;
    cout << fixed << setprecision(3);
    while (scanf("%d:%d", &h, &m), h || m)
    {
        double df = fabs(m * 6 - h * 30 - m / 2.0);
        cout << (df < 180 ? df : 360 - df) << '\n';
    }
}
