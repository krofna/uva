#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    int n, A[100], k;
    ios::sync_with_stdio(false);
    while (cin >> n, n)
    {
        memset(A, 0, sizeof(A));
        for (int i = 0; i < n; ++i)
        {
            cin >> k;
            A[k]++;
        }
        
        bool flg = false;
        for (int i = 0; i < 100; ++i)
        {
            for (int j = 0; j < A[i]; ++j)
            {
                if (flg) cout << ' ';
                cout << i;
                flg = true;
            }
        }
        cout << '\n';
    }
}
