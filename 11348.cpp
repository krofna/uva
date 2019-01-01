#include <iostream>
#include <map>
#include <vector>
#include <iomanip>
#include <algorithm>
using namespace std;

int main()
{
    int k, n, m, a;
    cin >> k;
    for (int t = 1; t <= k; ++t)
    {
        cin >> n;
        map<int, int> M;
        vector<vector<int> > A(n);
        for (int i = 0; i < n; ++i)
        {
            cin >> m;
            A[i].resize(m);
            for (int j = 0; j < m; ++j)
                cin >> A[i][j];
            sort(A[i].begin(), A[i].end());
            auto it = unique(A[i].begin(), A[i].end());
            A[i].resize(distance(A[i].begin(), it));
            for (int j = 0; j < A[i].size(); ++j)
                M[A[i][j]]++;
        }
        cout << "Case " << t << ":";
        vector<int> B(n);
        int uu = 0;
        for (int i = 0; i < n; ++i)
        {
            int u = 0;
            for (int j = 0; j < A[i].size(); ++j)
                if (M[A[i][j]] == 1)
                    ++u;
            B[i] = u;
            uu += u;
        }
        for (int i = 0; i < n; ++i)
            cout << setprecision(6) << fixed << " " << B[i] * 100. / uu << "%";
        cout << '\n';
    }
}
