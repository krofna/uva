#include <iostream>
using namespace std;

int main()
{
    int n, A[1000], c, p;
    while (cin >> n, n)
    {
        for (int i = 0; i < n; ++i)
            A[i] = 1000001;

        bool f = true;
        for (int i = 0; i < n; ++i)
        {
            cin >> c >> p;
            if (i + p >= 0 && i + p < n && A[i + p] == 1000001)
                A[i + p] = c;
            else
                f = false;
        }
        if (f)
        {
            for (int i = 0; i < n; ++i)
            {
                if (i) cout << ' ';
                cout << A[i];
            }
        }
        else
            cout << -1;
        cout << '\n';
    }
}
