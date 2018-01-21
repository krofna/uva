#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    int t, A[10][10];
    cin >> t;
    while (t--)
    {
        memset(A, 0, sizeof(A));
        for (int i = 0; i < 5; ++i)
            for (int j = 0; j <= i; ++j)
                cin >> A[i * 2][j * 2];

        for (int i = 1; i <= 4; ++i)
            for (int j = 0; j <= i * 2; ++j)
                if (j % 2)
                    A[i * 2][j] = (A[i * 2 - 2][j - 1] - A[i * 2][j - 1] - A[i * 2][j + 1]) / 2;

        for (int i = 0; i < 4; ++i)
            for (int j = 0; j <= i * 2 + 1; ++j)
                A[i * 2 + 1][j] = A[i * 2 + 2][j] + A[i * 2 + 2][j + 1];

        for (int i = 0; i < 9; ++i)
        {
            for (int j = 0; j <= i; ++j)
            {
                cout << A[i][j];
                if (j != i) cout << ' ';
            }
            cout << '\n';
        }
    }
}
