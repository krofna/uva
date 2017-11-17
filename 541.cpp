#include <iostream>
using namespace std;

int main()
{
    int n;
    while (cin >> n, n)
    {
        bool B[100][100];
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                cin >> B[i][j];

        int R[100] = {}, C[100] = {};
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                R[i] += B[i][j], C[j] += B[i][j];

        bool rf = false, cf = false;
        int r = -1, c = -1;
        for (int i = 0; i < n; ++i)
        {
            if (R[i] % 2)
            {
                if (rf) r = -1;
                else r = i;
                rf = true;
            }
            if (C[i] % 2)
            {
                if (cf) c = -1;
                else c = i;
                cf = true;
            }
        }
        if (r != -1 && c != -1)
            cout << "Change bit (" << r + 1 << "," << c + 1 << ")\n";
        else
            cout << (rf || cf ? "Corrupt\n" : "OK\n");
    }
}
