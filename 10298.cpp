#include <iostream>
#include <string>
#include <vector>
using namespace std;

typedef vector<int> vi;

void init(string& P, vi& b)
{
    int i = 0, j = -1; b[0] = -1;
    while (i < P.size())
    {
        while (j >= 0 && P[i] != P[j]) j = b[j];
        b[++i] = ++j;
    }
}

int kmp(string& T, string& P, vi& b)
{
    int ret = 0;
    int i = 0, j = 0;
    while (i < T.size())
    {
        while (j >= 0 && T[i] != P[j]) j = b[j];
        ++i; ++j;
        if (j == P.size())
            j = b[j], ++ret;
    }
    return ret;
}

int main()
{
    string T, P;
    ios::sync_with_stdio(false);
    while (cin >> P, P != ".")
    {
        T = P + P;
        vi b;
        b.resize(P.size() + 1);
        init(P, b);
        cout << kmp(T, P, b) - 1 << '\n';
    }
}
