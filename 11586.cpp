#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    cin.ignore();
    while (n--)
    {
        string s;
        getline(cin, s);
        int m = 0, f = 0;
        for (char c : s)
        {
            if (c == 'M')
                ++m;
            else if (c == 'F')
                ++f;
        }
        if (m == 1 || m != f)
            cout << "NO ";
        cout << "LOOP\n";
    }
}
