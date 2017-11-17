#include <iostream>
using namespace std;

unsigned ipow(unsigned b, unsigned p)
{
    if (p == 0)
        return 1;
    if (p % 2 == 0)
    {
        unsigned ip = ipow(b, p / 2);
        return ip * ip;
    }
    return b * ipow(b, p - 1);
}

int main()
{
    unsigned t, N;
    cin >> t;
    while (t--)
    {
        cin >> N;
        
        if (N == 0)
        {
            cout << "Armstrong\n";
            continue;
        }
        
        unsigned n = 0, A[10], M = N;
        while (M)
        {
            A[n++] = M % 10;
            M /= 10;
        }
        
        unsigned sum = 0;
        for (int i = 0; i < n; ++i)
            sum += ipow(A[i], n);

        cout << (sum == N ? "Armstrong\n" : "Not Armstrong\n");
    }
}
