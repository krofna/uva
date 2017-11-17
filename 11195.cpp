#include <iostream>
using namespace std;

int n, t = 1, c, d, e, m = 0;
string S[15];

void bt(int k)
{
    if (k == n)
    {
        ++m;
        return;
    }

    for (int i = 0; i < n; ++i)
    {
        int j = 1 << i, l = 1 << (n - 1 - k + i), o = 1 << (i + k);
        if (S[k][i] == '.' && !(c & j) && !(d & o) && !(e & l))
        {
            c |= j; d |= o; e |= l;
            bt(k + 1);
            c &= ~j; d &= ~o; e &= ~l;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    while (cin >> n, n)
    {
        for (int i = 0; i < n; ++i)
            cin >> S[i];
        m = c = d = e = 0;
        bt(0);
        cout << "Case " << t++ << ": " << m << '\n';
    }
}
