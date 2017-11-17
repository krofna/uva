// TODO: vidi krofnino
#include <iostream>
using namespace std;

int main()
{
    int t, n, p, h;
    cin >> t;
    while (t--)
    {
        cin >> n >> p;
        bool W[3650] = {};
        int cnt = 0;
        for (int i = 0; i < p; ++i)
        {
            cin >> h;
            int x = h - 1;
            while (x < n)
            {
                if (!W[x] && (x % 7 != 5) && (x % 7 != 6))
                {
                    W[x] = true;
                    ++cnt;
                }
                x += h;
            }
        }
        cout << cnt << '\n';
    }
}
