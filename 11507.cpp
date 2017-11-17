#include <iostream>
using namespace std;

char inv(char c)
{
    if (c == '-')
        return '+';
    return '-';
}

int main()
{
    int l;
    while (cin >> l, l)
    {
        string c = "+x", s;
        while (--l)
        {
            cin >> s;
            if (c[1] == 'x' && s[0] != 'N')
            {
                c[0] = (c[0] == '+' ? s[0] : inv(s[0]));
                c[1] = s[1];
            }
            else if (c[1] == s[1])
            {
                c[0] = (c[0] == '+' ? inv(s[0]) : s[0]);
                c[1] = 'x';
            }
        }
        cout << c << '\n';
    }
}
