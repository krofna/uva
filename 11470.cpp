#include <iostream>
using namespace std;

int A[10][10];

int sum(int k, int n)
{
    int sum = (n == 1 ? 0 : -A[k][k]);
    for (int y = k; y < k + n; ++y)
        sum += A[y][k] + A[k][y] + A[k + n - 1][y] + A[y][k + n - 1];
    return sum - A[k][k + n - 1] - A[k + n - 1][k] - A[k + n - 1][k + n - 1];
}

int main()
{
    int n, t = 1;
    while (cin >> n, n)
    {
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                cin >> A[i][j];

        cout << "Case " << t++ << ':';
        for (int i = 0; i < (n + 1) / 2; ++i)
            cout << ' ' << sum(i, n - 2 * i);
        cout << '\n';
    }
}
