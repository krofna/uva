#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int p, q, A[10];
    cin >> p;
    while (p--)
    {
        cin >> q;
        for (int j = 0; j < 10; ++j)
            cin >> A[j];
        nth_element(A, A + 2, A + 10, greater<int>());
        cout << q << " " << A[2] << '\n';
    }
}
