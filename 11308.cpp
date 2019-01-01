#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string name;
        cin.ignore();
        getline(cin, name);
        int m, n, b;
        cin >> m >> n >> b;
        map<string, int> M;
        for (int i = 0; i < m; ++i)
        {
            string in;
            int c;
            cin >> in >> c;
            M[in] = c;
        }
        vector<pair<int, string> > A;
        for (int i = 0; i < n; ++i)
        {
            int k, c = 0;
            string rname;
            cin.ignore();
            getline(cin, rname);
            cin >> k;
            for (int j = 0; j < k; ++j)
            {
                string req;
                int am;
                cin >> req >> am;
                c += M[req] * am;
            }
            if (c <= b)
                A.emplace_back(c, rname);
        }
        for (char& c : name)
            c = toupper(c);
        cout << name << '\n';
        sort(A.begin(), A.end());
        for (auto& p : A)
            cout << p.second << '\n';
        if (A.empty())
            cout << "Too expensive!\n";
        cout << '\n';
    }
}
