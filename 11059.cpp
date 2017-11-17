#include <iostream>
using namespace std;

int main()
{
    long long n, A[18], t = 1;
    while (cin >> n)
    {
        for (int i = 0; i < n; ++i)
            cin >> A[i];

        long long m = 0;
        for (int i = 0; i < n; ++i)
        {
            long long k = 1;
            for (int j = i; j < n; ++j)
            {
                k *= A[j];
                m = max(m, k);
            }
        }
        cout << "Case #" << t++ << ": The maximum product is " << m << ".\n\n";
    }
}
