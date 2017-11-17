#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    int n, k, x;
    while (cin >> n, n)
    {
        multiset<int> S;
        long long sum = 0;
        for (int i = 0; i < n; ++i)
        {
            cin >> k;
            for (int j = 0; j < k; ++j)
            {
                cin >> x;
                S.insert(x);
            }
            auto lo = S.begin();
            auto hi = prev(S.end());
            sum += *hi - *lo;
            S.erase(lo);
            S.erase(hi);
        }
        cout << sum << '\n';
    }
}
