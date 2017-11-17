#include <iostream>
#include <map>
#include <vector>
using namespace std;

map<char, int> G;
int B = 0;

void dfs(char c)
{
    if (B & 1 << (c - 'A'))
        return;

    B |= 1 << (c - 'A');
    int f = G[c];
    for (int i = 0; i < 26; ++i)
        if (f & (1 << i))
            dfs('A' + i);

    cout << c;
}

int main()
{
    string s;
    vector<string> A;    
    while (cin >> s, s != "#")
        A.push_back(s);
    
    for (int i = 1; i < A.size(); ++i)
        for (int j = 0; j < A[i].size() && j < A[i - 1].size() && (j == 0 || A[i][j - 1] == A[i - 1][j - 1]); ++j)
            if (A[i - 1][j] != A[i][j])
                G[A[i][j]] |= 1 << (A[i - 1][j] - 'A');
    
    for (auto& i : G)
        dfs(i.first);
    
    cout << '\n';
}
