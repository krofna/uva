#include <iostream>
#include <vector>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<bool> vb;

int dfs(int x, vvi& G, vb& B)
{
    B[x] = true;
    int sum = 1;
    for (int i = 0; i < G[x].size(); ++i)
        if (!B[G[x][i]])
            sum += dfs(G[x][i], G, B);
    return sum;
}

int main()
{
    ios::sync_with_stdio(false);
    int a, b, e, p;
    while (cin >> a >> b >> e >> p)
    {
        vvi G(e), H(e);
        for (int i = 0; i < p; ++i)
        {
            int x, y;
            cin >> x >> y;
            G[x].push_back(y);
            H[y].push_back(x);
        }
        int s = 0, z = 0, w = 0;
        for (int i = 0; i < e; ++i)
        {
            vb B(e), C(e);
            int f = dfs(i, G, B);
            int g = dfs(i, H, C);
            if (e - f < a)
                s++;
            if (e - f < b)
                z++;
            if (g > b)
                w++;
        }
        cout << s << '\n' << z << '\n' << w << '\n';
    }
}
