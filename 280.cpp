#include <iostream>
#include <vector>
using namespace std;

vector<vector<int> > G;
int n, p, q, v, m, c;

void flood(bool* B, int v)
{
    for (int k : G[v])
    {
        if (!B[k])
        {
            c++;
            B[k] = true;
            flood(B, k);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    while (cin >> n, n)
    {
        G.resize(n);
        while (cin >> p, p)
            while (cin >> q, q)
                G[p - 1].push_back(q - 1);

        cin >> m;
        while (m--)
        {
            cin >> v;
            bool B[100] = {};
            c = 0;
            flood(B, v - 1);
            cout << n - c;
            for (int i = 0; i < n; ++i)
                if (!B[i])
                    cout << ' ' << i + 1;
            cout << '\n';
        }
        G.clear();
    }
}
