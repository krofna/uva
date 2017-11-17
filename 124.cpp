#include <iostream>
#include <map>
#include <sstream>
using namespace std;

map<char, int> G;
char A[20], c, d;

bool place(int c, pair<char, int> d)
{
    int f = 0;
    for (int i = 0; i < c; ++i)
    {
        if (A[i] == d.first)
            return false;
        f |= 1 << (A[i] - 'a');
    }
    A[c] = d.first;
    return !(f & d.second);
}

void backtrack(int c)
{
    if (c == G.size())
    {
        for (int i = 0; i < G.size(); ++i)
            cout << A[i];
        cout << '\n';
        return;
    }
    for (auto& j : G)
        if (place(c, j))
            backtrack(c + 1);
}

int main()
{
    string a, b;
    bool flg = false;
    while (getline(cin, a) && getline(cin, b))
    {
        if (flg) cout << '\n';
        flg = true;

        istringstream ssa(a), ssb(b);
        while (ssa >> c) G[c];
        while (ssb >> c >> d) G[c] |= 1 << (d - 'a');
        backtrack(0);
        G.clear();
    }
}
