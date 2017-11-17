#include <iostream>
#include <algorithm>
using namespace std;

int A[5];

bool in()
{
    bool b = false;
    for (int i = 0; i < 5; ++i)
        cin >> A[i], b |= (A[i] != 0);
    return b;
}

int op(int a, int b, int j)
{
    if (j == 0) return a + b;
    if (j == 1) return a - b;
    return a * b;
}

bool rec(int p[], int q, int i)
{
    if (i == 5)
        return q == 23;
    for (int j = 0; j < 3; ++j)
        if (rec(p, op(q, A[p[i]], j), i + 1))
            return true;
    return false;
}

int main()
{
    while (in())
    {
        int p[5] = {0, 1, 2, 3, 4};
        bool f = false;
        do
        {
            if (rec(p, A[p[0]], 1))
            {
                f = true;
                break;
            }
        } while (next_permutation(p, p + 5));
        cout << (f ? "Possible\n" : "Impossible\n");
    }
}
