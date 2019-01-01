#include <iostream>
using namespace std;

int main()
{
    int n, A[10002];
    while (cin >> n, n)
    {
        for (int i = 0; i < n; ++i)
            cin >> A[i + 1];
        A[0] = A[n];
        A[n + 1] = A[1];
        int p = 0;
        for (int i = 1; i <= n; ++i)
            if (A[i] > A[i - 1] && A[i] > A[i + 1] ||
                A[i] < A[i - 1] && A[i] < A[i + 1])
                p++;
        cout << p << '\n';
    }
}
