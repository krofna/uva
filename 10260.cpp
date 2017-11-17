#include <iostream>
#include <algorithm>
using namespace std;

int f(char c)
{
    string A[] = { "BFPV", "CGJKQSXZ", "DT", "L", "MN", "R" };
    for (int j = 0; j < 6; ++j)
        if (find(A[j].begin(), A[j].end(), c) != A[j].end())
            return j + 1;
    return 0;
}

int main()
{
    string s;
    while (cin >> s)
    {
        auto end = unique(s.begin(), s.end(),[](char a, char b){return f(a) == f(b);});
        for (auto i = s.begin(); i != end; ++i)
            if (int j = f(*i))
                cout << j;
        cout << '\n';
    }
}
