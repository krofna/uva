#include <iostream>
#include <vector>
using namespace std;

void dfs(vector<vector<int> >& G, vector<bool>& B, int k)
{
    if (B[k])
        return;
    
    B[k] = true;
    for (int i = 0; i < G[k].size(); ++i)
        dfs(G, B, G[k][i]);
}

void print(int n)
{
    cout << '+';
    for (int i = 0; i < 2 * n - 1; ++i)
        cout << '-';
    cout << "+\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    int t, n, e;
    cin >> t;
    for (int r = 1; r <= t; ++r)
    {
        cin >> n;
        vector<vector<int> > G(n);
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                if (cin >> e, e)
                    G[i].push_back(j);

        vector<bool> B(n);
        dfs(G, B, 0);
        cout << "Case " << r << ":\n";        
        for (int i = 0; i < n; ++i)
        {
            vector<bool> C(n);
            C[i] = true;
            dfs(G, C, 0);
            print(n);
            for (int j = 0; j < n; ++j)
            {
                cout << '|';
                if (B[j] && (i == j || !C[j]))
                    cout << 'Y';
                else
                    cout << 'N';
            }
            cout << "|\n";
        }
        print(n);
    }
}
