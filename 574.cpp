#include <iostream>
#include <set>
using namespace std;

int t, n, A[12];
set<string> S;

void f(int k, int b)
{
    if (k != n)
    {
        f(k + 1, b | (1 << k));
        f(k + 1, b);
        return;
    }
    int s = 0;
    for (int i = 0; i < n; ++i)
        if (b & (1 << i))
            s += A[i];

    if (s == t)
    {
        string sol;
        bool g = false;
        for (int i = 0; i < n; ++i)
        {
            if (b & (1 << i))
            {
                if (g) sol += '+';
                sol += to_string(A[i]);
                g = true;
            }
        }
        auto p = S.insert(sol);
        if (p.second)
            cout << sol << '\n';
    }
}

int main()
{
    while (cin >> t >> n, n)
    {
        for (int i = 0; i < n; ++i)
            cin >> A[i];

        S.clear();
        cout << "Sums of " << t << ":\n";
        f(0, 0);
        if (S.empty())
            cout << "NONE\n";
    }
}
