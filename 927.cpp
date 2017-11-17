#include <iostream>
#include <sstream>
using namespace std;

typedef unsigned long long ull;

ull A[30], s = 0, d, k, c;

ull a(int n, int i = 0)
{
    return (i == s) ? A[i] : A[i] + n * a(n, i + 1);
}

int main()
{
    cin >> c;
    while (c--)
    {
        s = 0;
        cin >> s;
        for (int i = 0; i <= s; ++i)
            cin >> A[i];
        cin >> d >> k;
        int n = 0;
        for (int i = 0; i < k; i += n * d) ++n;
        cout << a(n) << endl;
    }
}
