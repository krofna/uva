#include <iostream>
#include <vector>
using namespace std;

int n, t = 1, P[16+16];
vector<int> S;

void f(int b)
{
    int k = S.size();
    if (k == n)
    {
        if (P[S.front() + S.back()])
        {
            for (int i = 0; i < k; ++i)
            {
                if (i) cout << ' ';
                cout << S[i];
            }
            cout << '\n';
        }
        return;
    }
    for (int i = 1; i <= n; ++i)
    {
        if (!(b & (1 << i)) && P[i + S.back()])
        {
            S.push_back(i);
            f(b | (1 << i));
            S.pop_back();
        }
    }
}

int main()
{
    bool flg = false;
    for (int j = 2; j < 16 + 16; ++j)
    {
        P[j] = true;
        for (int i = 2; i < j; ++i)
            if (j % i == 0)
                P[j] = false;
    }

    while (cin >> n)
    {
        if (flg) cout << '\n';
        flg = true;
        cout << "Case " << t++ << ":\n";
        S.push_back(1);
        f(1 << 1);
        S.pop_back();
    }
}
