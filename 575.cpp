#include <iostream>
using namespace std;

int main()
{
    string s;
    while (cin >> s, s != "0")
    {
        int sum = 0;
        for (int i = 0; i < s.size(); ++i)
            sum += (s[i] - '0') * ((1 << (s.size() - i)) - 1);
        cout << sum << '\n';
    }
}
