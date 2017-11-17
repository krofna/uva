#include <iostream>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <vector>
#include <iomanip>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    cin.ignore(2);
    cout << fixed << setprecision(4);
    while (t--)
    {
        unordered_map<string, int> M;
        string s;
        int n = 0;
        while (getline(cin, s), !s.empty())
            M[s]++, n++;

        // for performance's sake avoid std::map
        vector<pair<string, int> > V(M.begin(), M.end());
        sort(V.begin(), V.end());
        for (auto i : V)
            cout << i.first << ' ' << i.second * 100 / float(n) << '\n';
        if (t) cout << '\n';
    }
}
