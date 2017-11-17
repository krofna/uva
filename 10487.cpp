#include <iostream>
using namespace std;

int main()
{
    int n, m, l, A[1000], t = 1;
    while (cin >> n, n)
    {
        cout << "Case " << t++ << ":\n";
        for (int i = 0; i < n; ++i)
            cin >> A[i];
        cin >> m;
        for (int i = 0; i < m; ++i)
        {
            cin >> l;
            unsigned d = -1, b;
            for (int j = 0; j < n; ++j)
                for (int k = j + 1; k < n; ++k)
                    if (abs(A[j] + A[k] - l) < d)
                        d = abs(A[j] + A[k] - l), b = A[j] + A[k];
            cout << "Closest sum to " << l << " is " << b << ".\n";
        }
    }
}
