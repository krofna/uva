#include <iostream>
#include <map>
#include <string>
#include <algorithm>
using namespace std;

typedef pair<string, int> si;

bool cmp(const si& f, const si& s)
{
    return f.second < s.second;
}

int main()
{
    int n;
    while (cin >> n, n)
    {
        map<string, int> M;
        for (int k = 0; k < n; ++k)
        {
            int A[5];
            for (int i = 0; i < 5; ++i)
                cin >> A[i];
            sort(A, A + 5);
            string s;
            for (int i = 0; i < 5; ++i)
                s += to_string(A[i]);
            M[s]++;
        }
        int bst = max_element(M.begin(), M.end(), cmp)->second;
        int sum = 0;
        for (const si& p : M)
            if (p.second == bst)
                sum += bst;
        cout << sum << '\n';
    }
}
