#include <iostream>
#include <vector>
#include <array>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef vector<array<array<int, 2>, 2> > vaa;

void update(vaa& B, int k, int l, int d)
{
    if (d >= B[k][0][0])
    {
        B[k][1][0] = B[k][0][0]; // copy value
        B[k][1][1] = B[k][0][1]; // copy id
        B[k][0][0] = d; // set value
        B[k][0][1] = l; // set id
    }
    else if (d > B[k][1][0])
    {
        B[k][1][0] = d; // set value
        B[k][1][1] = l; // set id
    }
}

int dfs1(vvi& G, vaa& B, vb& C, int k)
{
    C[k] = true;
    for (int l : G[k])
        if (!C[l])
            update(B, k, l, 1 + dfs1(G, B, C, l));
    return B[k][0][0];
}

int lo, hi;

void dfs2(vvi& G, vaa& B, vb& C, vi& R, int k, int p)
{
    C[k] = true;
    for (int l : G[k])
        if (!C[l])
            dfs2(G, B, C, R, l, 1 + max((B[k][0][1] != l ? B[k][0][0] : B[k][1][0]), p));
    R[k] = max(B[k][0][0], p);
    lo = min(lo, R[k]);
    hi = max(hi, R[k]);
}

int main()
{
    int n;
    while (cin >> n)
    {
        vvi G(n);
        vaa B(n);
        vb C(n), D(n);
        vi R(n);
        for (int i = 0; i < n; ++i)
        {
            int m;
            cin >> m;
            for (int j = 0; j < m; ++j)
            {
                int k;
                cin >> k;
                G[i].push_back(k - 1);
            }
        }
        dfs1(G, B, C, 0);
        lo = 5000, hi = 0;
        dfs2(G, B, D, R, 0, 0);
        cout << "Best Roots  :";
        bool flg = true;
        for (int i = 0; i < n; ++i)
            if (R[i] == lo)
                cout << " " << i + 1;
        cout << "\nWorst Roots :";
        flg = true;
        for (int i = 0; i < n; ++i)
            if (R[i] == hi)
                cout << " " << i + 1;
        cout << '\n';
    }
}
