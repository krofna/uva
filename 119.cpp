#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    bool flg = false;
    int n;
    while (cin >> n)
    {
        if (flg)
            cout << '\n';
        flg = true;
        
        string A[10], s;
        int B[10] = {0}, c, k;
        for (int i = 0; i < n; ++i)
            cin >> A[i];
        
        for (int i = 0; i < n; ++i)
        {
            cin >> s >> c >> k;
            if (!k)
                continue;
            
            B[distance(A, find(A, A + n, s))] -= c - c % k;
            for (int j = 0; j < k; ++j)
            {
                cin >> s;
                B[distance(A, find(A, A + n, s))] += c / k;
            }
        }

        for (int i = 0; i < n; ++i)
            cout << A[i] << ' ' << B[i] << '\n';
    }
}
