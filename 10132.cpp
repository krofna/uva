#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

typedef const pair<string, int> si;

int main()
{
    int t;
    cin >> t;
    string s;
    cin.ignore();
    getline(cin, s);
    while (t--)
    {
        int n = 0, cnt = 0;
        vector<string> A;
        while (getline(cin, s), !s.empty())
        {
            A.push_back(s);
            n += s.size();
            cnt++;
        }
        map<string, int> M;
        int m = n / (cnt / 2);
        for (int i = 0; i < A.size(); ++i)
            for (int j = 0; j < A.size(); ++j)
                if (i != j)
                    if (A[i].size() + A[j].size() == m)
                        M[A[i] + A[j]]++;

        auto x = max_element(M.begin(), M.end(), [] (si& p1, si& p2)
        {
            return p1.second < p2.second;
        });
        cout << x->first << '\n';
        if (t) cout << '\n';
    }
}
