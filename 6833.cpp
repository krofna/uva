#include <iostream>
using namespace std;

typedef basic_string<int> istring;

int main()
{
    string s;
    int x;
    while (cin >> s >> x)
    {
        int a = s[0] - '0';
        for (int i = 1; i < s.size(); i += 2)
        {
            if (s[i] == '+')
                a += s[i + 1] - '0';
            else if (s[i] == '*')
                a *= s[i + 1] - '0';
        }
        istring z;
        for (int i = 0; i < s.size(); ++i)
            z.push_back(s[i] - '0');
        for (int i = 1; i < z.size(); i += 2)
            if (z[i] == '*' - '0')
                z.replace(i - 1, 3, 1, z[i - 1] * z[i + 1]), i -= 2;

        int b = z[0];
        for (int i = 1; i < z.size(); i += 2)
            b += z[i + 1];

        if (a == x && b == x)
            cout << "U\n";
        else if (a == x)
            cout << "L\n";
        else if (b == x)
            cout << "M\n";
        else
            cout << "I\n";
    }
}
