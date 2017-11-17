#include <iostream>
#include <sstream>
#include <map>
using namespace std;

map<char, int> G;
char A[20];
bool flg;

bool pl(pair<char, int> p, int k)
{
    int f = 0;
    for (int i = 0; i < k; ++i)
    {
        if (A[i] == p.first)
            return false;
        f |= (1 << (A[i] - 'A'));
    }
    A[k] = p.first;
    return !(p.second & f);
}

void bt(int k)
{
    if (k == G.size())
    {
        flg = false;
        for (int i = 0; i < G.size(); ++i)
        {
            if (i) cout << ' ';
            cout << A[i];
        }
        cout << '\n';
        return;
    }
    
    for (auto& p : G)
        if (pl(p, k))
            bt(k + 1);
}

int main()
{
    int t;
    cin >> t;
    cin.ignore();
    while (t--)
    {
        cin.ignore();
        string s;
        getline(cin, s);
        istringstream iss(s);
        char c;
        while (iss >> c)
            G[c];        
        getline(cin, s);
        istringstream is(s);
        while (is >> s)
            G[s[0]] |= (1 << (s[2] - 'A'));
        flg = true;
        bt(0);
        if (flg) cout << "NO\n";
        if (t) cout << '\n';
        G.clear();
    }
}
