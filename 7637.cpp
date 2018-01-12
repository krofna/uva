#include <iostream>
#include <vector>
using namespace std;

int t, n;

string run()
{
    int m = -1;
    bool bd = false;
    cin >> n;
    vector<int> A(n);
    for (int i = 0; i < n; ++i)
    {
        int k;
        cin >> k;
        if (k < n && k >= 0)
            A[k]++;
        else
            bd = true;
        m = max(m, k);
    }
    if (bd)
        return "invalid";

    string s(m, '(');
    for (int i = 1; i <= m; ++i)
        if (A[i]-- <= 0)
            return "invalid";

    for (; m > 0; A[m--] = 0)
    {
        s += ")";
        if (A[m - 1]-- <= 0)
            return "invalid";
        for (int i = 0; i < A[m]; ++i)
        {
            s += "()";
            if (A[m - 1]-- <= 0)
                return "invalid";
        }
    }
    return A[0] ? "invalid" : s;
}

int main()
{
    ios::sync_with_stdio(false);
    cin >> t;
    for (int T = 1; T <= t; ++T)
        cout << "Case " << T << ": " << run() << '\n';
}

