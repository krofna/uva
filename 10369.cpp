#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <algorithm>
#include <cmath>
#include <iomanip>
using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef priority_queue<ii, vii, greater<ii> > pqii;

int sq(int a) { return a * a; }

int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        int s, p;
        cin >> s >> p;
        vector<vector<int> > D(p, vector<int>(p));
        vector<int> X(p), Y(p);
        for (int i = 0; i < p; ++i)
            cin >> X[i] >> Y[i];
        for (int i = 0; i < p; ++i)
            for (int j = 0; j < p; ++j)
                D[i][j] = sq(X[i] - X[j]) + sq(Y[i] - Y[j]);

        pqii Q;
        vector<int> C(p, -1);
        Q.emplace(0, 0);
        while (!Q.empty())
        {
            int w, x;
            tie(w, x) = Q.top(), Q.pop();
            if (C[x] == -1)
            {
                C[x] = w;
                for (int i = 0; i < p; ++i)
                    if (C[i] == -1)
                        Q.emplace(D[i][x], i);
            }
        }
        sort(C.begin(), C.end());
        double d = sqrt(*max_element(C.begin(), C.end() - s + 1));
        cout << setprecision(2) << fixed << d << '\n';
    }
}

