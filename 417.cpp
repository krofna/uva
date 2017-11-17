#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

int n = 0;
vector<string> V;
map<string, int> M;

void gen(string s)
{
    V.push_back(s);
    if (s.size() == 5) return;
    for (char c = s.back() + 1; c <= 'z'; ++c)
        gen(s + c);
}

int main()
{
    V.reserve(83681);
    for (char c = 'a'; c <= 'z'; ++c)
        gen(string(1, c));
    sort(V.begin(), V.end(), [](const string& a, const string& b)
    {
        if (a.size() != b.size())
            return a.size() < b.size();
        return a < b;
    });
    for (int i = 0; i < V.size(); ++i)
        M[V[i]] = i + 1;
    string s;
    while (cin >> s)
        cout << M[s] << '\n';
}
