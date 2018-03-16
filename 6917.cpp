#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main()
{
    int t;
    ios::sync_with_stdio(false);
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        int n;
        cin >> n;
        char A['z' - 'a' + 1];
        for (int i = 0; i < 'z' - 'a' + 1; ++i)
            A[i] = 'A' + i;

        for (int i = 0; i < n; ++i)
        {
            char a, b;
            cin >> a >> b;
            for (int i = 0; i < 'z' - 'a' + 1; ++i)
                if (A[i] == b)
                    A[i] = a;
        }
        for (int i = 0; i < s.size(); ++i)
            if (s[i] != '_')
                s[i] = A[s[i] - 'A'];
        cout << s << '\n';
    }
}
