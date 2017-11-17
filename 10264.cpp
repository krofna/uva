#include <iostream>
using namespace std;

int main()
{
    int n;
    while (cin >> n)
    {
        int k, A[1 << 15] = {}, mx = 0;
        for (int i = 0; i < (1 << n); ++i)
        {
            cin >> k;
            for (int j = 1; j < (1 << n); j <<= 1)
                A[i ^ j] += k;
        }
        for (int i = 0; i < (1 << n); ++i)
            for (int j = 1; j < (1 << n); j <<= 1)
                mx = max(mx, A[i] + A[i ^ j]);
        cout << mx << '\n';
    }
}
