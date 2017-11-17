#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        if (s.find('D') == s.npos)
            cout << "Possible\n";
        else
            cout << "You shall not pass!\n";
    }
}
