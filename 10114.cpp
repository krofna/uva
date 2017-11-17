#include <iostream>
using namespace std;

int main()
{
    int m, r, dm[101];
    double d, l, dp[101];
    while (cin >> m >> d >> l >> r, m >= 0)
    {
        for (int i = 0; i < r; ++i)
            cin >> dm[i] >> dp[i];
        
        dm[r] = 101;
        
        double cv = d + l;
        double ml = l / double(m);
        int cm = 0, fm = -1;
        for (int i = 1; i <= r && fm == -1; ++i)
        {
            for (; cm < dm[i] && fm == -1; ++cm)
            {
                cv *= (1.0 - dp[i - 1]);
                if (cv > l)
                    fm = cm;
                else
                    l -= ml;
            }
        }
        cout << fm << " month";
        if (fm != 1) cout << "s";
        cout << '\n';
    }
}
