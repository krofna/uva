#include <iostream>
using namespace std;

int main()
{
    int l;
    string s;
    while (cin >> l, l)
    {
        cin >> s;
        int i = s.find_first_not_of('.');
        char t = s[i];
        unsigned min = (t == 'Z' ? 0 : -1), curr = 0;
        for (++i; i != s.size(); ++i)
        {
            ++curr;
            if (s[i] == t)
                curr = 0;
            else if (s[i] == 'Z')
            {
                min = 0;
                break;
            }
            else if (s[i] != '.')
            {
                if (curr < min)
                    min = curr;
                t = s[i];
                curr = 0;
            }
        }
        cout << min << '\n';
    }
}
