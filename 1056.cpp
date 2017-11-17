#include <iostream>
#include <unordered_map>
#include <cstring>
#include <algorithm>
using namespace std;

int main()
{
    int p, r, c, d, t = 1;
    while (cin >> p >> r, p || r)
    {
        unordered_map<string, int> M;        
        int k = 0, G[50][50];
        for (int i = 0; i < p; ++i)
            for (int j = 0; j < p; ++j)
                G[i][j] = (i == j ? 0 : 100);
        
        for (int i = 0; i < r; ++i)
        {
            string a, b;
            cin >> a >> b;
            auto p = M.emplace(a, k);
            if (p.second) k++;
            auto q = M.emplace(b, k);
            if (q.second) k++;
            c = p.first->second;
            d = q.first->second;
            G[c][d] = 1;
            G[d][c] = 1;
        }
        for (int k = 0; k < p; ++k)
            for (int i = 0; i < p; ++i)
                for (int j = 0; j < p; ++j)
                    G[i][j] = min(G[i][j], G[i][k] + G[k][j]);

        int o = 0;
        for (int i = 0; i < p; ++i)
            o = max(o, *max_element(G[i], G[i] + p));
        
        cout << "Network " << t++ << ": ";
        if (o != 100)
            cout << o << "\n\n";
        else
            cout << "DISCONNECTED\n\n";
    }
}
