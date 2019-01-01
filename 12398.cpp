#include <iostream>
#include <cstring>
using namespace std;

int d1[] = {1, -1, 0, 0};
int d2[] = {0, 0, -1, 1};
int t = 1, A[3][3];

bool ok(int a, int b)
{
    return a >= 0 && b >= 0 && a < 3 && b < 3;
}

int main()
{
    string s;
    while (getline(cin, s), cin)
    {
        memset(A, 0, sizeof(A));
        for (char c : s)
        {
            int k = c - 'a';
            int r = k / 3, s = k % 3;
            A[r][s]++;
            for (int i = 0; i < 4; ++i)
                if (ok(r + d1[i], s + d2[i]))
                    A[r + d1[i]][s + d2[i]]++;
        }
        cout << "Case #" << t++ << ":\n";
        for (int i = 0; i < 3; ++i)
        {
            for (int j = 0; j < 3; ++j)
            {
                if (j) cout << ' ';
                cout << A[i][j] % 10;
            }
            cout << '\n';
        }
    }
}
