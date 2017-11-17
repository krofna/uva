#include <iostream>
#include <set>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    int n, m, k;
    while (cin >> n >> m, n || m)
    {
        set<int> S;
        int cnt = 0;
        for (int i = 0; i < n + m; ++i)
        {
            cin >> k;
            if (!S.insert(k).second)
                cnt += 1;
        }
        cout << cnt << '\n';
    }
}
