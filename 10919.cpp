#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int k, m, A[100], c, r, d;
    while (cin >> k, k)
    {
        cin >> m;
        for (int i = 0; i < k; ++i)
            cin >> A[i];

        bool p = true;
        for (int i = 0; i < m; ++i)
        {
            cin >> r >> c;
            int f = 0;
            for (int j = 0; j < r; ++j)
            {
                cin >> d;
                if (find(A, A + k, d) != A + k)
                    ++f;
            }
            if (f < c)
                p = false;
        }
        cout << (p ? "yes" : "no") << '\n';
    }
}
