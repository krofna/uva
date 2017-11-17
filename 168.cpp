#include <iostream>
#include <sstream>
#include <vector>
#include <tuple>
#include <cstring>
using namespace std;

vector<int> G['Z' - 'A' + 1];
bool C['Z' - 'A' + 1];
char th, mn;
int k;

pair<int, int> nei(int u, int v)
{
    auto& A = G[v];
    for (int i = 0; i < A.size(); ++i)
        if (!C[A[i]] && A[i] != u)
            return make_pair(v, A[i]);
    return make_pair(-1, v);
}

char dfs(int u, int v, int w)
{
    do
    {
        if (w == k)
        {
            cout << char(u + 'A') << ' ';
            C[u] = true;
            w = 0;
        }
        tie(u, v) = nei(u, v);
        w++;
    } while (u != -1);
    return char(v + 'A');
}

int main()
{
    ios_base::sync_with_stdio(false);
    string s;
    while (cin >> s, s != "#")
    {
        s.pop_back();
        istringstream iss(s);
        while (getline(iss, s, ';'))
            for (int i = 2; i < s.size(); ++i)
                G[s[0] - 'A'].push_back(s[i] - 'A');

        cin >> mn >> th >> k;
        memset(C, false, sizeof(C));
        cout << '/' << dfs(th - 'A', mn - 'A', 0) << '\n';
        for (auto& V : G)
            V.clear();        
    }
}
