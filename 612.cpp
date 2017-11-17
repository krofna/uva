#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;

int main()
{
    int t, n, m;
    string A[100];
    cin >> t;
    for (int z = 0; z < t; ++z)
    {
        if (z)
            cout << '\n';

        cin >> n >> m;
        vii B(m);
        for (int i = 0; i < m; ++i)
        {
            cin >> A[i];
            int k = 0;
            for (int j = 0; j < n - 1; ++j)
                for (int l = j + 1; l < n; ++l)
                    if (A[i][j] > A[i][l])
                        ++k;

            B[i] = make_pair(i, k);
        }
        stable_sort(B.begin(), B.end(), [](const ii& a, const ii& b)
        {
            return a.second < b.second;
        });
        for (auto p : B)
            cout << A[p.first] << '\n';
    }
}
