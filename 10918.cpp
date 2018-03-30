#include <iostream>
#include <cstring>
using namespace std;

typedef long long ll;

ll dp1[31], dp2[31];

ll f(int n);

ll g(int n)
{
    if (dp2[n] != -1) return dp2[n];
    return dp2[n] = f(n - 2) + g(n - 2);
}

ll f(int n)
{
    if (dp1[n] != -1) return dp1[n];
    return dp1[n] = 3 * f(n - 2) + 2 * g(n - 2);
}

int main()
{
    memset(dp1, -1, sizeof(dp1));
    memset(dp2, -1, sizeof(dp2));
    dp1[0] = 1;
    dp1[1] = 0;
    dp1[2] = 3;
    dp2[0] = 1;
    dp2[1] = 0;
    dp2[2] = 1;
    int n;
    while (cin >> n, n != -1)
        cout << f(n) << '\n';
}
