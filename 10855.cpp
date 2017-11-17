#include <iostream>
#include <vector>
using namespace std;

typedef vector<string> vs;

int N, n;

vs rot(vs& s)
{
    vs r(n, string(n, 0));
    for (int y = 0; y < n; ++y)
        for (int x = 0; x < n; ++x)
            r[x][n - y - 1] = s[y][x];
    return r;
}

int mth(vs& S, vs& s, int x0, int y0)
{
    for (int y = 0; y < n; ++y)
        for (int x = 0; x < n; ++x)
            if (s[y][x] != S[y0 + y][x0 + x])
                return 0;
    return 1;
}

int mch(vs& S, vs& s)
{
    int ret = 0;
    for (int y = 0; y <= N - n; ++y)
        for (int x = 0; x <= N - n; ++x)
            ret += mth(S, s, x, y);
    return ret;
}

int main()
{
    while (cin >> N >> n, N || n)
    {
        vs S(N), s0(n);
        for (int i = 0; i < N; ++i)
            cin >> S[i];
        for (int i = 0; i < n; ++i)
            cin >> s0[i];

        vs s1 = rot(s0);
        vs s2 = rot(s1);
        vs s3 = rot(s2);
        
        cout << mch(S, s0) << ' ' << mch(S, s1) << ' '
             << mch(S, s2) << ' ' << mch(S, s3) << '\n';
            
    }
}
