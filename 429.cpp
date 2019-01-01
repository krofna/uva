#include <iostream>
#include <map>
#include <vector>
#include <queue>
using namespace std;

map<string, vector<string> > G;

bool cmp(const string& a, const string& b)
{
    if (a.size() != b.size())
        return false;

    int mm = 0;
    for (int i = 0; i < a.size(); ++i)
        if (a[i] != b[i])
            if (mm++ == 1)
                return false;
    return true;
}

int bfs(string& a, string& b)
{
    queue<pair<string, int> > Q;
    map<string, bool> B;
    Q.emplace(a, 0);
    B[a] = true;
    while (!Q.empty())
    {
        string t;
        int k;
        tie(t, k) = Q.front();
        if (t == b)
            return k;

        Q.pop();
        for (string& d : G[t])
            if (!B[d])
                Q.emplace(d, k + 1), B[d] = true;
    }
    return -1;
}

int main()
{
    int t;
    cin >> t;
    cin.ignore(2);
    while (t--)
    {
        string s;
        G.clear();
        while (getline(cin, s), s != "*")
        {
            auto& v = G[s];
            for (auto& p : G)
                if (cmp(p.first, s))
                    p.second.push_back(s), v.push_back(p.first);
        }
        while (getline(cin, s), cin && !s.empty())
        {
            int in = s.find(' ');
            string a = s.substr(0, in);
            string b = s.substr(in + 1);
            cout << s << ' ' << bfs(a, b) << '\n';
        }
        if (t) cout << '\n';
    }
}
