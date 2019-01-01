#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int t, u = 1, s[3], z[3], w[3], A[3][1000], U[3][2000], D[3][1000];
    cin >> t;
    while (t--)
    {
        cout << "Case #" << u++ << ":\n";
        for (int j = 0; j < 3; ++j)
        {
            cin >> s[j];
            for (int i = 0; i < s[j]; ++i)
                cin >> A[j][i];
            sort(A[j], A[j] + s[j]);
            //s[j] = distance(A[j], unique(A[j], A[j] + s[j]));
        }
        z[0] = distance(U[0], set_union(A[1], A[1] + s[1], A[2], A[2] + s[2], U[0]));
        z[1] = distance(U[1], set_union(A[0], A[0] + s[0], A[2], A[2] + s[2], U[1]));
        z[2] = distance(U[2], set_union(A[0], A[0] + s[0], A[1], A[1] + s[1], U[2]));
        int mx = 0;
        for (int j = 0; j < 3; ++j)
        {
            w[j] = distance(D[j], set_difference(A[j], A[j] + s[j], U[j], U[j] + z[j], D[j]));
            mx = max(mx, w[j]);
        }
        for (int j = 0; j < 3; ++j)
        {
            if (w[j] != mx) continue;
            cout << j + 1 << " " << mx;
            for (int i = 0; i < mx; ++i)
                cout << " " << D[j][i];
            cout << '\n';
        }
    }
}
