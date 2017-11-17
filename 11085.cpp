#include <iostream>
using namespace std;

int r[8], p[8], t = 1;

bool in()
{
    for (int i = 0; i < 8; ++i)
        cin >> r[i], r[i] -= 1, p[i] = r[i];
    return (bool)cin;
}

int bt(int c)
{
    for (int i = 0; i < c - 1; ++i)
        if (r[i] == r[c - 1] || c - 1 - i == abs(r[c - 1] - r[i]))
            return 8;

    if (c == 8)
    {
        int q = 0;
        for (int i = 0; i < 8; ++i)
            if (r[i] != p[i])
                q++;
        return q;
    }
    int ro = r[c], mi = 8;
    for (int i = 0; i < 8; ++i)
    {
        r[c] = i;
        mi = min(mi, bt(c + 1));
    }
    return mi;
}

int main()
{
    while (in())
        cout << "Case " << t++ << ": " << bt(0) << '\n';
}
