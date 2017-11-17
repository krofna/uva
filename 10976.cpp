#include <iostream>
using namespace std;

int main()
{
    int k;
    while (cin >> k)
    {
        int n = 0, A[10000], B[10000];
        for (int i = k + 1; i <= 2 * k; ++i)
            if ((i * k) % (i - k) == 0)
                A[n] = i, B[n++] = (i * k) / (i - k);
        cout << n << '\n';
        for (int i = 0; i < n; ++i)
            cout << "1/" << k << " = 1/" << B[i] << " + 1/" << A[i] << '\n';
    }
}
