#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int s, d;
        cin >> s >> d;
        if (d <= s)
        {
            int a = (s + d);
            a += (a % 2);
            a /= 2;
            int b = s - a;
            if (a + b == s && a - b == d)
                cout << a << ' ' << s - a << '\n';
            else
                cout << "impossible\n";
        }
        else
            cout << "impossible\n";
    }
}
