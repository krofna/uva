#include <iostream>
#include <list>
using namespace std;

int main()
{
    string s;
    while (getline(cin, s), cin)
    {
        list<char> l;
        auto i = l.end();
        for (char c : s)
        {
            if (c == '[')
                i = l.begin();
            else if (c == ']')
                i = l.end();
            else
                l.insert(i, c);
        }
        for (char c : l)
            cout << c;
        cout << '\n';
    }
}
