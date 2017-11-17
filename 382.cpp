#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "PERFECTION OUTPUT\n";
    while (cin >> n, n)
    {
        int m = 0;
        for (int i = 1; i < n; ++i)
            if (n % i == 0)
                m += i;
        
        int d = 0, nn = n;
        while (nn)
        {
            ++d;
            nn /= 10;
        }
        
        cout << string(5 - d, ' ') << n << "  ";
        
        if (m < n)
            cout << "DEFICIENT\n";
        else if (m > n)
            cout << "ABUNDANT\n";
        else
            cout << "PERFECT\n";
    }
    cout << "END OF OUTPUT\n";
}
