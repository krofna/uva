#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
#include <utility>
using namespace std;

typedef const pair<int, string> is;

map<string, int> M;
map<string, string> N;
map<string, bool> B;
string name, s;

int main()
{
    while (getline(cin, name), name[0] != '0')
    {
        M[name];
        while (getline(cin, s), s[0] != '1')
        {
            if (all_of(s.begin(), s.end(), [](char c)
                       {return !isalpha(c) || isupper(c);}))
                name = s, M[s];
            else
            {
                auto it = N.find(s);
                if (it == N.end())
                {
                    M[name]++;
                    N[s] = name;
                }
                else if (it->second != name && !B[it->first])
                    M[N[s]]--, B[it->first] = true;
            }
        }
        vector<pair<int, string> > A;
        for (auto& p : M)
            A.emplace_back(p.second, p.first);
        sort(A.begin(), A.end(), [](is& p, is& q)
        {
            if (p.first == q.first)
                return p.second < q.second;
            return p.first > q.first;
        });
        for (auto& p : A)
            cout << p.second << ' ' << p.first << '\n';
        M.clear();
        N.clear();
        B.clear();
    }
}
