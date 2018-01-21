#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    long long t, n, A[100][100];
    cin >> t;
    for (int u = 1; u <= t; ++u)
    {
        string s;
        cin >> s >> s >> n;
        bool sym = true;
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                cin >> A[i][j];
                if (A[i][j] < 0)
                    sym = false;
            }
        }
        for (int i = 0; i < (n + 1) / 2; ++i)
            for (int j = 0; j < n; ++j)
                if (A[i][j] != A[n - i - 1][n - j - 1])
                    sym = false;
        cout << "Test #" << u << ": ";
        if (sym)
            cout << "Symmetric.\n";
        else
            cout << "Non-symmetric.\n";
    }
}
