#include <iostream>
#include <string>
using namespace std;

int main()
{
    int k, l;
    while (cin >> k, k)
    {
        string s;
        cout << "The parity of ";
        l = 0;
        while (k)
        {
            s += '0' + k % 2;
            l += k % 2;
            k /= 2;
        }
        for (int i = 0; i < s.size(); ++i)
            cout << s[s.size() - i - 1];
        cout << " is " << l << " (mod 2).\n";
    }
}
