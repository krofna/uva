#include <iostream>
using namespace std;

int R[8], rr, cc, n, ctr;

bool place(int c, int r)
{
    for (int i = 0; i < c; ++i)
        if (R[i] == r || abs(R[i] - r) == abs(i - c))
            return false;

    R[c] = r;
    return true;
}

void backtrack(int c)
{
    if (c == 8 && R[cc] == rr)
    {
        if (ctr < 10) cout << ' ';
        cout << ctr++ << "      ";
        for (int i = 0; i < 8; ++i)
        {
            if (i) cout << ' ';
            cout << R[i] + 1;
        }
        cout << '\n';
        return;
    }
    for (int i = 0; i < 8; ++i)
        if (place(c, i))
            backtrack(c + 1);
}

int main()
{
    cin >> n;
    while (n--)
    {
        cin >> rr >> cc;
        --rr; --cc;
        cout << "SOLN       COLUMN\n";
        cout << " #      1 2 3 4 5 6 7 8\n\n";
        ctr = 1;
        backtrack(0);
        if (n) cout << '\n';
    } 
}
