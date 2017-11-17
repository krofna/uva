#include <iostream>
#include <vector>
using namespace std;

void flood(vector<char>* G, bool* B, int k)
{
    B[k] = true;
    for (char c : G[k])
        if (!B[c - 'A'])
            flood(G, B, c - 'A');
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        char m;
        cin >> m;
        cin.ignore();
        vector<char> G[26];
        string s;
        while (getline(cin, s), !s.empty())
        {
            G[s[0] - 'A'].push_back(s[1]);
            G[s[1] - 'A'].push_back(s[0]);
        }
        int cnt = 0;
        bool B[26] = {};
        for (char c = 'A'; c <= m; ++c)
            if (!B[c - 'A'])
                cnt++, flood(G, B, c - 'A');
        cout << cnt << '\n';
        if (t)
            cout << '\n';
    }
}
