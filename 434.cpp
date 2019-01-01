#include <iostream>
#include <algorithm>
#include <numeric>
using namespace std;

int main()
{
    int t, k, A[8][8], F[8], S[8], U[16];
    cin >> t;
    while (t--)
    {
        cin >> k;
        for (int i = 0; i < k; ++i)
            cin >> F[i];
        for (int i = 0; i < k; ++i)
            cin >> S[i];

        int m = 0;
        for (int i = 0; i < k; ++i)
            for (int j = 0; j < k; ++j)
                m += min(F[i], S[j]);

        sort(F, F + k);
        sort(S, S + k);
        int u = distance(U, set_union(S, S + k, F, F + k, U));
        int n = accumulate(U, U + u, 0);
        cout << "Matty needs at least " << n << " blocks, ";
        cout << "and can add at most " << m - n << " extra blocks.\n";
    }
}

