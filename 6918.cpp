#include <iostream>
using namespace std;

typedef long long ll;
ll a, b;

ll f()
{
    for (ll i = 63; i >= 0; --i)
        if (((1ll << i) & a) != ((1ll << i) & b))
            return (1ll << (i + 1)) - 1;
    return 0;
}

int main()
{
    int t;
    ios::sync_with_stdio(false);
    cin >> t;
    for (int T = 1; T <= t; ++T)
    {
        cin >> a >> b;
        cout << "Case " << T << ": " << (b | f()) << " " << (b & ~f()) << '\n';
    }
}
