#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    string s;
    while (cin >> s)
    {
        sort(s.begin(), s.end());
        auto i = find_if(s.begin(), s.end(), [](char a){return a != '0';});
        swap(s[0], s[distance(s.begin(), i)]);
        long long a = stoll(s);
        sort(s.begin(), s.end(), greater<char>());
        long long b = stoll(s);
        cout << b << " - " << a << " = " << b - a << " = 9 * " << (b - a) / 9 << '\n';
    }
}
