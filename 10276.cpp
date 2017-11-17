#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

int t, n, A[50], k;

bool sq(int x)
{
    int r = sqrt(x);
    return r * r == x;
}

int main()
{
    cin >> t;
    while (t--)
    {
        cin >> n;
        memset(A, 0, sizeof(A));
        for (k = 1; ; ++k)
        {
            bool f = false;
            for (int i = 0; i < n; ++i)
            {
                if (A[i] == 0 || sq(A[i] + k))
                {
                    A[i] = k;
                    f = true;
                    break;
                }
            }
            if (!f) break;
        }
        cout << k - 1 << '\n';
    }
}
