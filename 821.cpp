#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int a, b, G[100][100], t = 1, N = 100;
    while (cin >> a >> b, a + b)
    {
        for (int i = 0; i < N; ++i)
            for (int j = 0; j < N; ++j)
                G[i][j] = (i == j ? 0 : 100);

        do
        {
            G[--a][--b] = 1;
            cin >> a >> b;
        } while (a + b);
        for (int k = 0; k < N; ++k)
            for (int i = 0; i < N; ++i)
                for (int j = 0; j < N; ++j)
                    G[i][j] = min(G[i][j], G[i][k] + G[k][j]);

        int sum = 0, n = 0;
        for (int i = 0; i < N; ++i)
            for (int j = 0; j < N; ++j)
                if (i != j && G[i][j] < 100)
                    sum += G[i][j], n++;

        float mean = (float)sum / n;
        cout << setprecision(3) << fixed << "Case " << t++;
        cout << ": average length between pages = " << mean << " clicks\n";
    }
}
