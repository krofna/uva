#include <iostream>
#include <cstring>
using namespace std;

int n, r, c, b, A[100][100], B[100][100];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

bool ok(int a, int b)
{
    return a >= 0 && a < r && b >= 0 && b < c;
}

int main()
{
    while (cin >> n >> r >> c >> b, n || r || c || b)
    {
        for (int i = 0; i < r; ++i)
            for (int j = 0; j < c; ++j)
                cin >> A[i][j];

        for (int i = 0; i < b; ++i)
        {
            memcpy(B, A, sizeof(A));
            for (int j = 0; j < r; ++j)
                for (int k = 0; k < c; ++k)
                    for (int l = 0; l < 4; ++l)
                        if (ok(j + dx[l], k + dy[l]))
                            if (A[j + dx[l]][k + dy[l]] == (A[j][k] + 1) % n)
                                B[j + dx[l]][k + dy[l]] = A[j][k];
            memcpy(A, B, sizeof(A));
        }
        for (int i = 0; i < r; ++i)
        {
            for (int j = 0; j < c; ++j)
            {
                if (j) cout << ' ';
                cout << A[i][j];
            }
            cout << '\n';
        }
    }
}
