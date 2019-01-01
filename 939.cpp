#include <iostream>
#include <map>
#include <vector>
using namespace std;

map<string, string> M;
map<string, vector<string> > P;

string solve(const string& s)
{
    if (!M[s].empty())
        return M[s];

    vector<string>& q = P[s];
    vector<string> p = {solve(q[0]), solve(q[1])};
    if (p[0] == "dominant" || p[1] == "dominant")
    {
        if (p[0] != "non-existent" && p[1] != "non-existent")
            return "dominant";
        return "recessive";
    }
    if (p[0] == "recessive" && p[1] == "recessive")
        return "recessive";
    return "non-existent";
}

int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        string a, b;
        cin >> a >> b;
        if (b == "dominant" ||
            b == "recessive" ||
            b == "non-existent")
            M[a] = b;
        else
            P[b].push_back(a), M[b];
    }

    for (auto& p : M)
        cout << p.first << ' ' << solve(p.first) << '\n';
}
