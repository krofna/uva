#include <iostream>
using namespace std;

int t, b, sg, sb;

int sel(int* A, int* B)
{
    int r = 0;
    for (int i = 100; i > 0 && r < b; --i)
        while (A[i] && r < b)
            B[r++] = i, --A[i];
    return r;
}

void prnt(int* A)
{
    for (int i = 100; i > 0; --i)
        while (A[i]--)
            cout << i << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin >> t;
    while (t--)
    {
        cin >> b >> sg >> sb;
        int G[101] = {}, B[101] = {}, k;
        for (int i = 0; i < sg; ++i)
            cin >> k, G[k]++;
        for (int i = 0; i < sb; ++i)
            cin >> k, B[k]++;

        int P[100000], Q[100000], p, q;
        while (p = sel(G, P), q = sel(B, Q), p || q)
        {
            for (int i = 0; i < min(p, q); ++i)
            {
                if (P[i] > Q[i])
                    G[P[i] - Q[i]]++;
                else if (Q[i] > P[i])
                    B[Q[i] - P[i]]++;
            }
            int* D = p > q ? G : B;
            int* S = p > q ? P : Q;
            for (int i = min(p, q); i < max(p, q); ++i)
                D[S[i]]++;
            if (!min(p, q)) break;
        }
        if (p)
            cout << "green wins\n", prnt(G);
        else if (q)
            cout << "blue wins\n", prnt(B);
        else
            cout << "green and blue died\n";
        if (t) cout << '\n';
    }
}
