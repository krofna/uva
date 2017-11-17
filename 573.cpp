#include <iostream>
using namespace std;

int main()
{
    float h, u, d, f;
    while (cin >> h >> u >> d >> f, h)
    {
        f *= (u / 100.0);
        float c = 0;
        int i = 1;
        while (c + u <= h && c >= 0)
        {
            c += u;
            c -= d;
            u = max(0.f, u - f);
            ++i;
        }
        
        if (c < 0)
            cout << "failure on day " << i - 1 << "\n";
        else
            cout << "success on day " << i << "\n";
    }
}
