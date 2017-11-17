#include <iostream>
using namespace std;

int A[8][8], r[8];

int bt(int c)
{
    for (int i = 0; i < c - 1; ++i)
        if (r[i] == r[c - 1] || c - 1 - i == abs(r[c - 1] - r[i]))
            return 0;

    if (c == 8)
    {
        int sum = 0;
        for (int i = 0; i < 8; ++i)
            sum += A[r[i]][i];
        return sum;
    }
    int mx = 0;
    for (int i = 0; i < 8; ++i)
    {
        r[c] = i;
        mx = max(mx, bt(c + 1));
    }
    return mx;
}

int main()
{
    int k;
    cin >> k;
    while (k--)
    {
        for (int i = 0; i < 8; ++i)
            for (int j = 0; j < 8; ++j)
                cin >> A[i][j];
        cout.width(5); cout << bt(0) << '\n';
    }
}
