#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int t;
    cin >> t;
    for (int u = 1; u <= t; ++u)
    {
        int n, A[10];
        cin >> n;
        for (int i = 0; i < n; ++i)
            cin >> A[i];
        sort(A, A + n);
        cout << "Case " << u << ": " << A[n / 2] << '\n';
    }
}
