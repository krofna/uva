#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    int n, c, w, p;
    cin >> n;
    while (n--)
    {
        cin >> c;
        vector<string> R;
        map<string, int> N;
        map<string, set<string> > M;
        for (int i = 0; i < c; ++i)
        {
            string s, z;
            cin >> s >> w >> p;
            R.push_back(s);
            N[s] = p;
            for (int j = 0; j < w; ++j)
            {
                cin >> z;
                M[z].insert(s);
            }
        }
        string l, o, a;
        getline(cin, l);
        while (getline(cin, l), !l.empty())
            a += " " + l;

        replace_if(a.begin(), a.end(), [](char c){return !isalpha(c);}, ' ');
        istringstream iss(a);
        while (iss >> o)
        {
            auto it = M.find(o);
            if (it == M.end()) continue;
            for (const string& ca : it->second)
                --N[ca];
            M.erase(it);
        }
        bool f = false;
        for (string& s : R)
        {
            if (N[s] <= 0)
            {
                if (f) cout << ',';
                cout << s;
                f = true;
            }
        }
        if (!f)
            cout << "SQF Problem.";
        cout << '\n';
    }
}
