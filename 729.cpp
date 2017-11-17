#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int t, n, h;
    cin >> t;
    while (t--)
    {
        cin >> n >> h;
        string s(n - h, '0');
        s += string(h, '1');
        do
        {
            cout << s << '\n';
        } while (next_permutation(s.begin(), s.end()));
        if (t) cout << '\n';
    }
}
