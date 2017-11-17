#include <iostream>
using namespace std;

string M[10000];
int L[10000], H[10000], t, d, q, m;

int main()
{
    cin >> t;
    while (t--)
    {
        cin >> d;
        for (int i = 0; i < d; ++i)
            cin >> M[i] >> L[i] >> H[i];
        cin >> q;
        for (int i = 0; i < q; ++i)
        {
            cin >> m;
            int f = -1;
            for (int j = 0; j < d; ++j)
                if (L[j] <= m && m <= H[j])
                    f = f == -1 ? j : -2;
            if (f < 0)
                cout << "UNDETERMINED\n";
            else
                cout << M[f] << '\n';
        }
        if (t) cout << '\n';
    }
}
