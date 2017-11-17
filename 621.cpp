#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        string s;
        cin >> s;
        if (s == "1" || s == "4" || s == "78")
            cout << '+';
        else if (s.substr(s.size() - 2) == "35")
            cout << '-';
        else if (s[0] == '9')
            cout << '*';
        else
            cout << '?';
        cout << '\n';
    }
}
