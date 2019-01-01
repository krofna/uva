#include <iostream>
#include <queue>
#include <cmath>
using namespace std;

const size_t LEN = 'Z' - 'A' + 2;
const size_t EAR = LEN - 1;

int main()
{
    int n;
    while (cin >> n)
    {
        vector<int> G[LEN];
        vector<double> C(LEN);
        for (int i = 0; i < n; ++i)
        {
            char c;
            double f;
            string s;
            cin >> c >> f >> s;
            int p = c - 'A';
            C[p] = f;
            for (char d : s)
            {
                int q = d == '*' ? EAR : d - 'A';
                G[p].push_back(q);
                G[q].push_back(p);
            }
        }
        queue<int> Q;
        Q.push(EAR);
        vector<int> D(LEN, -1);
        D[EAR] = 0;
        while (!Q.empty())
        {
            int k = Q.front();
            Q.pop();
            for (int s : G[k])
                if (D[s] == -1)
                    D[s] = D[k] + 1, Q.push(s);
        }
        double maxd = 0, maxi = -1;
        for (int j = 0; j < EAR; ++j)
        {
            if (D[j] == -1) continue;
            double d = C[j] * pow(0.95, D[j] - 1);
            if (d > maxd)
                maxd = d, maxi = j;
        }
        cout << "Import from " << char('A' + maxi) << '\n';
    }
}
