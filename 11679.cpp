#include <algorithm>
#include <iostream>
using namespace std;

int main()
{
    int b, n, R[20], d, c, v;
    while (cin >> b >> n, b && n)
    {
        for (int i = 0; i < b; ++i)
            cin >> R[i];
        
        for (int i = 0; i < n; ++i)
        {
            cin >> d >> c >> v;
            R[d - 1] -= v;
            R[c - 1] += v;
        }
        
        if (all_of(R, R + b, [](int x){return x >= 0;}))
            cout << "S\n";
        else
            cout << "N\n";
    }
}
