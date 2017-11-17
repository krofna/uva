#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int t, n, k;
    cin >> t;
    while (t--)
    {
        cin >> n >> k;
        int A[100000];
        for (int i = 0; i < n; ++i)
            cin >> A[i];
        sort(A, A + n);
        int s = 0, c;
        for (c = 0; c < n && s + A[c] < k; ++c)
            s += A[c];
        cout << c << '\n';
    }
}
