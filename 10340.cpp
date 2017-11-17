#include <iostream>
using namespace std;

int main()
{
    string s, t;
    while (cin >> s >> t)
    {
        int k = 0;
        for (int i = 0; i < t.size() && k < s.size(); ++i)
            if (t[i] == s[k])
                ++k;
        
        cout << (k == s.size() ? "Yes\n" : "No\n");
    }
}
