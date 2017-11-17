#include <iostream>
#include <vector>
#include <utility>
using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<vii> Mat;

int main()
{
    int m, n, r, k;
    while (cin >> m >> n)
    {
        Mat M(n, vii());
        for (int j = 0; j < m; ++j)
        {
            cin >> r;
            int A[10000];
            for (int i = 0; i < r; ++i)
                cin >> A[i];
            
            for (int i = 0; i < r; ++i)
            {
                cin >> k;
                M[A[i] - 1].emplace_back(j + 1, k);
            }
        }
        cout << n << ' ' << m << '\n';
        for (int i = 0; i < n; ++i)
        {
            cout << M[i].size();
            for (auto& p : M[i])
                cout << ' ' << p.first;
            cout << '\n';
            for (int j = 0; j < M[i].size(); ++j)
            {
                if (j) cout << ' ';
                cout << M[i][j].second;
            }
            cout << '\n';
        }
    }
}
