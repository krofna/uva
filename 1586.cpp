#include <iostream>
#include <iomanip>
using namespace std;

float f(char c)
{
    switch (c)
    {
        case 'C': return 12.01;
        case 'H': return 1.008;
        case 'O': return 16.00;
        case 'N': return 14.01;
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        
        double mass = 0;
        for (int i = 0; i < s.size(); ++i)
        {
            if (i + 1 < s.size() && isdigit(s[i + 1]))
            {
                int d = s[i + 1] - '0';
                if (i + 2 < s.size() && isdigit(s[i + 2]))
                {
                    mass += (d * 10 + s[i + 2] - '0') * f(s[i]);
                    ++i;
                }
                else
                    mass += d * f(s[i]);
                ++i;
            }
            else
                mass += f(s[i]);
        }
    
        cout << setprecision(3) << fixed << mass << '\n';
    }
}
