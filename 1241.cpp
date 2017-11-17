#include <iostream>
#include <bitset>
using namespace std;

bool f(bitset<1<<10>& A, int a, int b, int& c)
{
    if (a == b)
        return A[a];
    
    int m = (a + b) / 2;
    bool l = f(A, a, m, c);
    bool r = f(A, m + 1, b, c);
    c += l != r;
    return l || r;
}

int main()
{
    int t, n, m, k;
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        bitset<1<<10> A; A.set();
        for (int i = 0; i < m; ++i)
        {
            cin >> k;
            A[k - 1] = 0;
        }
        int c = 0;
        f(A, 0, (1 << n) - 1, c);
        cout << c << '\n';
    }
}
