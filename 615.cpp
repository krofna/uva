#include <iostream>
#include <map>
#include <vector>
using namespace std;

typedef vector<int> vi;
typedef map<int, vi> mivi;
typedef map<int, bool> mib;

bool dfs(mivi& C, mib& D, int root)
{
    if (D[root]) return false;
    D[root] = true;
    for (int k : C[root])
        if (!dfs(C, D, k))
            return false;
    return true;
}

bool tree(mivi& P, mivi& C)
{
    if (P.empty()) return true;
    int root = -1;
    for (auto ivi : P)
    {
        if (ivi.second.empty())
        {
            if (root != -1) return false;
            else root = ivi.first;
        }
    }
    if (root == -1)
        return false;

    mib D;
    if (!dfs(C, D, root))
        return false;
    for (auto ivi : P)
        if (!D[ivi.first])
            return false;
    return true;
}

int main()
{
    int a, b, t = 1;
    while (cin >> a >> b, a >= 0 && b >= 0)
    {
        mivi P, C;
        while (a && b)
        {
            C[a].push_back(b); C[b];
            P[b].push_back(a); P[a];
            cin >> a >> b;
        }
        cout << "Case " << t++ << " is ";
        if (!tree(P, C)) cout << "not ";
        cout << "a tree.\n";
    }
}
