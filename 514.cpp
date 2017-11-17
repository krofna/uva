#include <iostream>
#include <stack>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    int n, A[1000], i, j;
    while (cin >> n, n)
    {
        while (cin >> A[0], A[0])
        {
            for (int i = 1; i < n; ++i)
                cin >> A[i];

            stack<int> S;
            for (i = 1, j = 0; i <= n; ++i)
            {
                if (i != A[j])
                    S.push(i);
                else
                    ++j;

                while (!S.empty() && S.top() == A[j])
                    S.pop(), ++j;
            }
            cout << (j == n ? "Yes" : "No") << '\n';
        }
        cout << '\n';
    }
}
