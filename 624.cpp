#include <iostream>
#include <cstring>
using namespace std;

int n, t, A[20], mx;
bool B[20], C[20];

void bt(int k, int c)
{
    if (c > n)
        return;

    if (k == t)
    {
        if (c > mx)
        {
            mx = c;
            memcpy(C, B, sizeof(B));
        }
        return;
    }
    B[k] = 1;
    bt(k + 1, c + A[k]);
    B[k] = 0;
    bt(k + 1, c);
}

int main()
{
    while (cin >> n >> t)
    {
        for (int i = 0; i < t; ++i)
            cin >> A[i];

        mx = 0;
        bt(0, 0);
        for (int i = 0; i < t; ++i)
            if (C[i])
                cout << A[i] << " ";
        cout << "sum:" << mx << '\n';
    }
}
