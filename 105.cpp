#include <iostream>
using namespace std;

int main()
{
    int l, h, r, M[10000] = {};
    while (cin >> l >> h >> r)
        for (int j = l; j < r; ++j)
            M[j] = max(M[j], h);

    bool f = false;
    for (int i = 1; i < 10000; ++i)
    {
        if (M[i] != M[i - 1])
        {
            if (f) cout << " ";
            cout << i << " " << M[i];
            f = true;
        }
    }
    cout << '\n';
}
