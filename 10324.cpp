#include <iostream>
#include <numeric>
using namespace std;

int main()
{
    string s;
    int n, A[1000000], p, q, u = 1;
    while (cin >> s >> n)
    {
        cout << "Case " << u++ << ":\n";
        A[0] = s[0] - '0';
        for (int i = 1; i < s.size(); ++i)
            A[i] = A[i - 1] + s[i] - '0';
        while (n--)
        {
            cin >> p >> q;
            if (p > q) swap(p, q);
            int l = (p > 0 ? A[p - 1] : 0), h = A[q];
            if ((l == h) || (h - l == q - p + 1))
                cout << "Yes\n";
            else
                cout << "No\n";
        }
    }
}
