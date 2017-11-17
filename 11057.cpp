#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n, m, A[10000];
    while (cin >> n)
    {
        for (int i = 0; i < n; ++i)
            cin >> A[i];
        
        sort(A, A + n);
        cin >> m;
        int a = 0, b = m;
        for (int i = 0; i < n; ++i)
        {
            int j = distance(A, lower_bound(A, A + n, m - A[i]));
            if (i != j && j != n && A[i] + A[j] == m)
            {
                if (abs(A[i] - A[j]) < abs(b - a))
                {
                    a = A[i];
                    b = A[j];
                }
            }
        }
        cout << "Peter should buy books whose prices are " << min(a, b) << " and " << max(a, b) << ".\n\n";
    }
}
