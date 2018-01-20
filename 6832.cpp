#include <iostream>
#include <limits>
using namespace std;

int INF = numeric_limits<int>::max();

int f(int i, bool* B, bool* C)
{
    int j = i;
    while (C[j] != B[i]) ++j;
    return j - i;
}

int main()
{
    int n, m, p;
    bool B[15], C[15], D[15];
    while (cin >> n >> m)
    {
        int o = 0;
        for (int i = 0; i < n; ++i)
            cin >> B[i], o += B[i];

        int k = 0, c = 0, d = 0;
        for (int i = 0; i < m; ++i)
        {
            cin >> p;
            for (int l = k; l < k + p; ++l)
                C[l] = i % 2, D[l] = !(i % 2), c += C[l], d += D[l];
            k += p;
        }

        int a = (c == o ? 0 : INF), b = (d == o ? 0 : INF);
        for (int i = 0; i < n; ++i)
        {
            if (c == o)
                if (int g = f(i, B, C))
                    C[i + g] = !C[i + g], a += g;
            if (d == o)
                if (int g = f(i, B, D))
                    D[i + g] = !D[i + g], b += g;
        }
        cout << min(a, b) << '\n';
    }
}
