#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, A[10] = {};
        cin >> n;
        for (int i = 1; i <= n; ++i)
        {
            int k = i;
            while (k)
                A[k % 10]++, k /= 10;
        }
        for (int i = 0; i < 10; ++i)
        {
            if (i) cout << ' ';
            cout << A[i];
        }
        cout << '\n';
    }
}
