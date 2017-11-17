#include <iostream>
#include <queue>
using namespace std;

int main()
{
    int n, k;
    while (cin >> n, n)
    {
        priority_queue<int, vector<int>, greater<int> > Q;
        for (int i = 0; i < n; ++i)
        {
            cin >> k;
            Q.push(k);
        }
        k = 0;
        while (Q.size() != 1)
        {
            int a = Q.top(); Q.pop();
            int b = Q.top(); Q.pop();
            k += a + b;
            Q.push(a + b);
        }
        cout << k << '\n';
    }
}
