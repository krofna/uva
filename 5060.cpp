#include <iostream>
using namespace std;

int t, n, k, A[1 << 15], P[1 << 15], M[1 << 15][15];

int f(int p, int q, int i)
{
    if (p == q)
        return p;
    
    int m = (p + q) / 2;
    int l = f(p, m, i - 1);
    int r = f(m + 1, q, i - 1);
    int al = A[l];
    A[l] -= A[r];
    A[r] -= al;
    int w = A[l] >= 0 ? l : r;
    M[w][i] = A[l] >= 0 ? r : l;
    A[w] = min(P[w], A[w] + k);
    return w;
}

int main()
{
    cin >> t;
    while (t--)
    {
        cin >> n >> k;
        for (int i = 0; i < 1 << n; ++i)
            cin >> A[i], P[i] = A[i];
        int w = f(0, (1 << n) - 1, n - 1);
        cout << w + 1 << '\n';
        for (int i = 0; i < n; ++i)
        {
            if (i) cout << " ";
            cout << M[w][i] + 1;
        }
        cout << '\n';
    }
}
