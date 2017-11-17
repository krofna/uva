#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    cin.ignore();
    while (t--)
    {
        string s;
        int A['Z' - 'A' + 1] = {}, ac = 0, ed = 0, vt = 0;
        while (getline(cin, s) && s[0] != '*')
        {
            A[s[1] - 'A']++;
            A[s[3] - 'A']++;
            ed++;
        }
        getline(cin, s);
        for (int i = 0; i < s.size(); i += 2)
        {
            if (!A[s[i] - 'A'])
                ac++;
            vt++;
        }
        cout << "There are " << vt - ed - ac << " tree(s) and " << ac << " acorn(s).\n";
    }
}
