#include <iostream>
using namespace std;

int m, n, A[100][100], t, c;

void ud(int r)
{
    int rs = n - 2 * r;
    for (int j = 0; j < rs; ++j)
        swap(A[r][r + j], A[r + rs - 1][r + j]);

    for (int i = 1; i < rs / 2; ++i)
    {
        swap(A[r + i][r], A[r + rs - 1 - i][r]);
        swap(A[r + i][r + rs - 1], A[r + rs - 1 - i][r + rs - 1]);
    }
}

void lr(int r)
{
    int rs = n - 2 * r;
    for (int j = 0; j < rs; ++j)
        swap(A[r + j][r], A[r + j][r + rs - 1]);

    for (int i = 1; i < rs / 2; ++i)
    {
        swap(A[r][r + i], A[r][r + rs - 1 - i]);
        swap(A[r + rs - 1][r + i], A[r + rs - 1][r + rs - 1 - i]);
    }
}

void id(int r)
{
    int rs = n - 2 * r;
    for (int j = 0; j < rs; ++j)
        swap(A[r][r + j], A[r + rs - 1 - j][r + rs - 1]);
    for (int j = 1; j < rs; ++j)
        swap(A[r + j][r], A[r + rs - 1][r + rs - 1 - j]);
}

void md(int r)
{
    int rs = n - 2 * r;
    for (int j = 0; j < rs - 1; ++j)
        swap(A[r + j][r], A[r][r + j]);
    for (int j = 0; j < rs; ++j)
        swap(A[r + rs - 1][r + j], A[r + j][r + rs - 1]);
}

void (*f[4])(int) = { ud, lr, md, id };

int main()
{
    ios::sync_with_stdio(false);
    cin >> m;
    while (m--)
    {
        cin >> n;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                cin >> A[i][j];

        int r = (n + 1) / 2;
        for (int i = 0; i < r; ++i)
        {
            cin >> t;
            for (int j = 0; j < t; ++j)
            {
                cin >> c;
                f[c - 1](i);
            }
        }
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (j) cout << ' ';
                cout << A[i][j];
            }
            cout << '\n';
        }
    }
}
