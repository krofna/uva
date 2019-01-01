#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <sstream>
using namespace std;

int main()
{
    int A[24], t;
    cin >> t;
    while (t--)
    {
        for (int i = 0; i < 24; ++i)
            cin >> A[i];

        map<string, pair<int, int> > M;
        map<string, int> C;
        vector<string> L;
        string l, p, c, d;
        cin.ignore();
        while (getline(cin, l), !l.empty())
            L.push_back(l);
        sort(L.begin(), L.end());
        for (string& l : L)
        {
            int po;
            istringstream iss(l);
            iss >> p >> d >> c >> po;
            int ho = stoi(d.substr(6, 2));
            if (c == "enter")
                M[p] = make_pair(po, ho);
            else if (c == "exit")
            {
                auto it = M.find(p);
                if (it != M.end())
                {
                    C[p] += 100 + abs(po - M[p].first) * A[M[p].second];
                    M.erase(it);
                }
            }
        }
        cout << setprecision(2) << fixed;
        for (auto& p : C)
            cout << p.first << " $" << (p.second + 200) / 100. << '\n';
        if (t) cout << '\n';
    }
}
