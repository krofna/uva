#include <iostream>
using namespace std;

int main()
{
    int n, m, b = 0;
    while (cin >> n >> m)
    {
        if (b) cout << '\n';
        b = 1;
        int A[41] = {};
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= m; ++j)
                A[i + j]++;
        int mx = 0;
        for (int i = 0; i < 41; ++i)
            mx = max(mx, A[i]);
        for (int i = 0; i < 41; ++i)
            if (A[i] == mx)
                cout << i << '\n';
    }
}
