#include <iostream>
#include <map>
using namespace std;

string M = "ABCDEFGHIJKLMNOPRSTUVWXY";

string tr(const string& s)
{
    return s.substr(0, 3) + "-" + s.substr(3, 4);
}

int main()
{
    int t, n;
    cin >> t;
    while (t--)
    {
        cin >> n;
        map<string, int> D;
        for (int i = 0; i < n; ++i)
        {
            string s, z;
            cin >> s;
            for (char c : s)
            {
                int k = M.find(c);
                if (k != M.npos)
                    c = '0' + 2 + k / 3;
                if (c != '-')
                    z += c;
            }
            D[z]++;
        }
        bool f = true;
        for (auto& si : D)
            if (si.second > 1)
                cout << tr(si.first) << " " << si.second << '\n', f = false;
        if (f) cout << "No duplicates.\n";
        if (t) cout << '\n';
    }
}
