#include <iostream>
#include <string>
#include <vector>
using namespace std;

const int maxn = 100;
int invp[maxn], ppow[maxn], pref[maxn + 1];

const int mod = 1000000009;
int add(int a, int b) { return (a += b) < mod? a : a - mod; }
int sub(int a, int b) { return (a -= b) >=  0? a : a + mod; }
int mul(int a, int b) { return 1LL * a * b % mod; }
int pwr(int a, int p) {
    if (p == 0) return 1;
    if (p & 1) return mul(a, pwr(a, p - 1));
    return pwr(mul(a, a), p / 2);
}
int inv(int a) { return pwr(a, mod - 2); }

void pre_hash(const string& s)
{
    for (int i = 0; i < s.size(); ++i)
        pref[i + 1] = add(pref[i], mul(s[i] - ' ' + 1, ppow[i]));
}

int substr_hash(int i, int j)
{
    return mul(invp[i], sub(pref[j + 1], pref[i]));
}

int solve(const string& s)
{
    int m = s.size();
    vector<int> divs;
    for (int i = 1; i <= m; ++i)
        if (m % i == 0)
            divs.push_back(i);

    pre_hash(s);
    for (int x : divs)
    {
        bool bad = false;
        for (int i = x; i < m && !bad; i += x)
            if (substr_hash(i, i + x - 1) != substr_hash(0, x - 1))
                bad = true;

        if (!bad)
            return x;
    }
    return m;
}

int main()
{
    invp[0] = ppow[0] = 1;
    for (int i = 1; i < maxn; ++i)
    {
        ppow[i] = mul(ppow[i - 1], 97);
        invp[i] = inv(ppow[i]);
    }
    int n;
    cin >> n;
    while (n--)
    {
        string P;
        cin >> P;
        cout << solve(P) << '\n';
        if (n) cout << '\n';
    }
}
