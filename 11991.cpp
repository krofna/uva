#include <iostream>
#include <vector>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

int main()
{
    ios::sync_with_stdio(false);
    int n, m, k, l;
    while (cin >> n >> m)
    {
        vvi A(1000000);
        for (int i = 0; i < n; ++i)
        {
            cin >> k;
            A[k - 1].push_back(i + 1);
        }
        for (int i = 0; i < m; ++i)
        {
            cin >> k >> l;
            if (k <= A[l - 1].size())
                cout << A[l - 1][k - 1] << '\n';
            else
                cout << 0 << '\n';
        }
    }
}
