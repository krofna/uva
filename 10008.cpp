#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<int, char> ic;

int main()
{
    int n;
    cin >> n;
    cin.ignore();
    char k = 'A';
    vector<ic> F('Z' - 'A' + 1);
    generate(F.begin(), F.end(), [&]{ return make_pair(0, -(k++)); });
    for (int i = 0; i < n; ++i)
    {
        string s;
        getline(cin, s);
        for (char c : s)
            if (isalpha(c))
                F[toupper(c) - 'A'].first++;
    }
    sort(F.begin(), F.end(), greater<pair<int, char>>());
    for (auto p : F)
        if (p.first)
            cout << char(-p.second) << ' ' << p.first << '\n';
}
