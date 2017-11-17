#include <iostream>
using namespace std;

int main()
{
    int t, n, A[1000];
    cin >> t;
    while (t--)
    {
        cin >> n;
        int k = 0;
        for (int i = 0; i < n; ++i)
        {
            cin >> A[i];
            for (int j = i - 1; j >= 0; --j)
                if (A[j] <= A[i])
                    ++k;
        }
        cout << k << '\n';
    }
}
