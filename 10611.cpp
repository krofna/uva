#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n, q, x, l, u, A[50000];
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> A[i];

    cin >> q;
    while (q--)
    {
        cin >> x;
        l = distance(A, lower_bound(A, A + n, x));
        u = distance(A, upper_bound(A, A + n, x));

        if (l == 0)
            cout << "X ";
        else
            cout << A[l - 1] << ' ';
        
        if (u == n)
            cout << "X\n";
        else
            cout << A[u] << '\n';
    }
}
