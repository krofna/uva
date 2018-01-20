#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

int main()
{
    int n, m, c, d;
    ios::sync_with_stdio(false);
    while (cin >> n >> m)
    {
        vi A(n, 0);
        int z = 0;
        vii M;
        for (int i = 0; i < m; ++i)
        {
            cin >> c >> d;
            M.emplace_back(c - 1, d - 1);
        }
        sort(M.begin(), M.end());
        for (ii& p : M)
        {
            tie(c, d) = p;
            int a = min(c, d), b = max(c, d);
            int s = A[a] ? A[a] : ++z;
            for (int i = a; i <= b; ++i)
                A[i] = s;
        }
        int d = 1 + 4 * z + count(A.begin(), A.end(), 0);
        for (int i = 0; i < n; ++i)
        {
            if (A[i] != 0)
            {
                int j = i;
                while (i + 1 < n && A[j] == A[i + 1]) ++i;
                d += 3 * (i - j - 1);
            }
        }
        cout << d << '\n';
    }
}
