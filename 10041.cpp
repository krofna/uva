#include <iostream>
using namespace std;

int main()
{
    int t, r, A[500];
    cin >> t;
    while (t--)
    {
        cin >> r;
        for (int i = 0; i < r; ++i)
            cin >> A[i];

        int m = 1000000000;
        for (int i = 0; i < r; ++i)
        {
            int d = 0;
            for (int j = 0; j < r; ++j)
                d += abs(A[j] - A[i]);
            m = min(m, d);
        }
        cout << m << '\n';
    }
}
