#include <iostream>
using namespace std;

int main()
{
    string s;
    while (getline(cin, s))
    {
        int n = 0, i = 0;
        while (i < s.size())
        {
            while (!isalpha(s[i]) && i < s.size()) ++i;
            if (isalpha(s[i])) ++n;
            while (isalpha(s[i]) && i < s.size()) ++i;
        }
        cout << n << '\n';
    }
}
