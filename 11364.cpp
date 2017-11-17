#include <iostream>
#include <tuple>
#include <algorithm>
using namespace std;

int main()
{
    int t, n, A[20], *min, *max;
    cin >> t;
    while (t--)
    {
        cin >> n;
        for (int i = 0; i < n; ++i)
            cin >> A[i];
        
        tie(min, max) = minmax_element(A, A + n);
        cout << 2 * (*max - *min) << '\n';
    }
}
