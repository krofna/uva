#include <iostream>
using namespace std;

int main()
{
    int t, n, m, A[8][28];
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                cin >> A[i][j];

        bool sug = true;
        for (int i = 0; i < m && sug; ++i)
        {
            int cnt = 0;
            for (int j = 0; j < n; ++j)
                if (A[j][i])
                    ++cnt;
            
            if (cnt != 2)
                sug = false;
        }
        for (int i = 0; i < m && sug; ++i)
        {
            for (int j = i + 1; j < m && sug; ++j)
            {
                bool eq = true;
                for (int k = 0; k < n; ++k)
                    if (A[k][i] != A[k][j])
                        eq = false;
                if (eq)
                    sug = false;
            }
        }
        cout << (sug ? "Yes" : "No") << '\n';
    }
}
