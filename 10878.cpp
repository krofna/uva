#include <iostream>
using namespace std;

int main()
{
    string s;
    getline(cin, s);
    while (getline(cin, s), s != "___________")
    {
        char c = 0;
        int i = 0;
        for (++i; i <= 5; ++i)
            if (s[i] == 'o')
                c |= (1 << (8 - i));
        for (++i; i <= 9; ++i)
            if (s[i] == 'o')
                c |= (1 << (8 - i + 1));
        cout << c;
    }
}
