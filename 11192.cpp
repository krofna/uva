#include <iostream>
using namespace std;

int main()
{
    int n;
    while (cin >> n, n)
    {
        string s;
        cin >> s;
        int sz = s.size() / n;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < sz / 2; ++j)
                swap(s[i * sz + j], s[(i + 1) * sz - 1 - j]);
        cout << s << '\n';
    }
}
