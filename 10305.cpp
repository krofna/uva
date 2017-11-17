#include <iostream>
#include <vector>
using namespace std;

typedef vector<int> vi;

void dfs(vi* A, bool* B, int k)
{
    if (B[k])
        return;

    B[k] = true;
    for (int i : A[k])
        dfs(A, B, i);

    cout << k + 1 << ' ';
}

int main()
{
    int n, m, a, b;
    while (cin >> n >> m, n || m)
    {
        vi A[100];
        while (m--)
        {
            cin >> a >> b;
            A[b - 1].push_back(a - 1);
        }
        bool B[100] = {0};
        for (int i = 0; i < n; ++i)
            dfs(A, B, i);
        cout << '\n';
    }
}
