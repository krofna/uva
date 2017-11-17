#include <iostream>
using namespace std;

int main()
{
    int n, b, h, w, H, p, a, min;
    while (cin >> n >> b >> h >> w)
    {
        min = 500001;
        for (int i = 0; i < h; ++i)
        {
            cin >> p;
            for (int j = 0; j < w; ++j)
            {
                cin >> a;
                if (a >= n && n * p < min)
                    min = n * p;
            }
        }
        if (min <= b)
            cout << min << '\n';
        else
            cout << "stay home\n";
    }
}
