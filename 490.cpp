#include <iostream>
using namespace std;


int main()
{
    string s[100], A[100];
    int n = 0;
    while (getline(cin, s[n]), cin && !s[n].empty()) n++;
    for (int i = 0; i < 100; ++i)
        A[i].resize(n, ' ');
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < s[n - i - 1].size(); ++j)
            A[j][i] = s[n - i - 1][j];
    int m = 100;
    while (A[m - 1] == string(n, ' ')) --m;
    for (int i = 0; i < m; ++i)
        cout << A[i] << '\n';
}
