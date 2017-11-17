#include <iostream>
using namespace std;

int main()
{
    int t, a, sum = 0;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        if (s == "donate")
        {
            cin >> a;
            sum += a;
        }
        else
            cout << sum << '\n';
    }
}
