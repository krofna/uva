#include <iostream>
#include <sstream>
using namespace std;

int gcd(int a, int b)
{
    return b ? gcd(b, a % b) : a;
}

int main()
{
    int n, m, k, A[100];
    cin >> n;
    cin.ignore();
    while (n--)
    {
        string in;
        getline(cin, in);
        istringstream ss(in);
        
        int m = 0;
        while (ss >> k) A[m++] = k;

        int max = 0;
        for (int i = 0; i < m - 1; ++i)
        {
            for (int j = i + 1; j < m; ++j)
            {
                int gc = gcd(A[i], A[j]);
                if (gc > max)
                    max = gc;
            }
        }
        cout << max << '\n';
    }
}
