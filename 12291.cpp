#include <iostream>
#include <vector>
using namespace std;

int n, m, m1, m2;
vector<string> A, B, C;

void put(int a, int b, char c)
{
    for (int i = 0; i < m1; ++i)
        for (int j = 0; j < m2; ++j)
            if (B[i][j] == '*')
                A[a + i][b + j] = c;
}

bool match(int a, int b)
{
    for (int i = 0; i < m1; ++i)
        for (int j = 0; j < m2; ++j)
            if (B[i][j] == '*' && A[a + i][b + j] != '*')
                return false;
    put(a, b, '.');
    return true;
}

bool done(int a, int b)
{
    bool f = true;
    for (int i = 0; i < n && f; ++i)
        for (int j = 0; j < n && f; ++j)
            if (A[i][j] == '*')
                f = false, put(a, b, '*');
    return f;
}

int main()
{
    while (cin >> n >> m, n || m)
    {
        A.resize(n);
        B.resize(m);
        for (int i = 0; i < n; ++i)
            cin >> A[i];

        C = A;
        for (int i = 0; i < m; ++i)
            cin >> B[i];
        while (!B.empty() && B.front().find('*') == string::npos)
            B.erase(B.begin());
        while (!B.empty() && B.back().find('*') == string::npos)
            B.pop_back();

        m1 = B.size();
        int mi = 10, ma = 0;
        for (int i = 0; i < m1; ++i)
        {
            if (B[i].find('*') != -1)
            {
                mi = min(mi, (int)B[i].find('*'));
                ma = max(ma, (int)B[i].rfind('*'));
            }
        }
        for (int i = 0; i < m1; ++i)
            B[i] = B[i].substr(mi, ma - mi + 1);

        m2 = B[0].size();
        bool f = true;
        for (int i = 0; i < n - m1 + 1 && f; ++i)
        {
            for (int j = 0; j < n - m2 + 1 && f; ++j)
            {
                if (match(i, j))
                    for (int k = i; k < n - m1 + 1 && f; ++k)
                        for (int l = 0; l < n - m2 + 1 && f; ++l)
                            if (match(k, l) && done(k, l))
                                cout << 1 << '\n', f = false;
                A = C;
            }
        }
        if (f) cout << 0 << '\n';
    }
}
