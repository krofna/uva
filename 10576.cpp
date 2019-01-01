#include <iostream>
using namespace std;

int main()
{
    int s, d;
    while (cin >> s >> d)
    {
        int g = 0;
        for (int i = 0; i < (1 << 12); ++i)
        {
            int sum = 0, sum2 = 0;
            for (int j = 0; j < 12; ++j)
            {
                if (j == 5) sum2 = sum;
                sum += i & (1 << j) ? s : -d;
            }
            if (sum < 0 || sum2 > 0) continue;
            bool f = true;
            for (int j = 0; j < 8; ++j)
            {
                sum2 -= i & (1 << j) ? s : -d;
                sum2 += i & (1 << (j + 5)) ? s : -d;
                if (sum2 > 0) f = false;
            }
            if (f)
                g = max(g, sum);
        }
        if (g)
            cout << g << '\n';
        else
            cout << "Deficit\n";
    }
}
