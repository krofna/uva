#include <iostream>
using namespace std;

int main()
{
    string s;
    while (cin >> s, s != "ENDOFINPUT")
    {
        cin.ignore();
        getline(cin, s);
        for (char c : s)
        {
            if (isupper(c))
            {
                int k = c - 'A' - 5;
                if (k < 0) k = 'Z' - 'A' + 1 + k;
                cout << char('A' + k);
            }
            else
                cout << c;
        }
        cout << '\n';
        cin >> s;
    }
}
