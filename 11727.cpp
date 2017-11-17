#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int t, u = 1, A[3];
    cin >> t;
    while (cin >> A[0] >> A[1] >> A[2], t--)
    {
        sort(A, A + 3);
        cout << "Case " << u++ << ": " << A[1] << '\n';
    }
}
