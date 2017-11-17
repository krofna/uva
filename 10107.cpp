#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int A[10000], n = 0;
    while (cin >> A[n++])
    {
        nth_element(A, A + n / 2, A + n);
        if (!(n % 2))
        {
            nth_element(A, A + n / 2 - 1, A + n);
            cout << (A[n / 2] + A[n / 2 - 1]) / 2 << '\n';
        }
        else
            cout << A[n / 2] << '\n';
    }
}
