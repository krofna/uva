#include <iostream>
#include <queue>
#include <algorithm>
#include <utility>
using namespace std;

int main()
{
    int t, n, m;
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        queue<pair<int, int> > Q;
        vector<int> V(n);
        for (int i = 0; i < n; ++i)
        {
            cin >> V[i];
            Q.emplace(i, V[i]);
        }
        sort(V.begin(), V.end(), greater<int>());
        int k = 0, po = -1;
        while (po != m)
        {
            if (Q.front().second >= V[k])
                po = Q.front().first, k++;
            else
                Q.push(Q.front());
            Q.pop();
        }
        cout << k << '\n';
    }
}
