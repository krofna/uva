#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int main()
{
    int g, p, s, z, A[100][100], S[100], R[100];
    while (cin >> g >> p, g || p)
    {
        for (int i = 0; i < g; ++i)
            for (int j = 0; j < p; ++j)
                cin >> A[i][j];

        cin >> s;
        for (int i = 0; i < s; ++i)
        {
            cin >> z;
            memset(S, 0, sizeof(S));
            for (int j = 0; j < z; ++j)
                cin >> S[j];

            memset(R, 0, sizeof(R));
            for (int j = 0; j < g; ++j)
                for (int k = 0; k < p; ++k)
                    R[k] += S[A[j][k] - 1];

            bool f = false;
            int mx = *max_element(R, R + p);
            for (int j = 0; j < p; ++j)
            {
                if (R[j] == mx)
                {
                    if (f) cout << ' ';
                    cout << j + 1;
                    f = true;
                }
            }

            cout << '\n';
        }
    }
}
