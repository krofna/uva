#include <iostream>
#include <array>
using namespace std;

typedef array<array<int, 10>, 10> arr;

int main()
{
    int t, n, m, a, b;
    arr A;
    cin >> t;
    for (int u = 1; u <= t; ++u)
    {
        cout << "Case #" << u << '\n';
        cin >> n;
        for (int i = 0; i < n; ++i)
        {
            string s;
            cin >> s;
            for (int j = 0; j < n; ++j)
                A[i][j] = s[j] - '0';
        }
        int in = 0;
        cin >> m;
        for (int i = 0; i < m; ++i)
        {
            string s;
            cin >> s;
            if (s == "row")
            {
                cin >> a >> b; a--; b--;
                for (int i = 0; i < n; ++i)
                    swap(A[a][i], A[b][i]);
            }
            else if (s == "col")
            {
                cin >> a >> b; a--; b--;
                for (int i = 0; i < n; ++i)
                    swap(A[i][a], A[i][b]);
            }
            else if (s == "transpose")
            {
                arr B = A;
                for (int i = 0; i < n; ++i)
                    for (int j = 0; j < n; ++j)
                        A[i][j] = B[j][i];
            }
            else if (s == "inc")
                ++in;
            else if (s == "dec")
                --in;
        }
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
                cout << (10 + (A[i][j] + in) % 10) % 10;
            cout << '\n';
        }
        cout << '\n';
    }
}
