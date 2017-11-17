#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n, q, A[10000], t = 1, x;
    while (cin >> n >> q, n || q)
    {
        cout << "CASE# " << t++ << ":\n";
        for (int i = 0; i < n; ++i)
            cin >> A[i];
        
        sort(A, A + n);
        for (int i = 0; i < q; ++i)
        {
            cin >> x;
            int y = distance(A, lower_bound(A, A + n, x));
            if (A[y] == x)
                cout << x << " found at " << y + 1 << '\n';
            else
                cout << x << " not found\n";
        }
    }
}
