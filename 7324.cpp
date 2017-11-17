#include <iostream>
using namespace std;

string B[7], A[7] = {
{"xxxxx.....x.xxxxx.xxxxx.x...x.xxxxx.xxxxx.xxxxx.xxxxx.xxxxx......"},
{"x...x.....x.....x.....x.x...x.x.....x.........x.x...x.x...x...x.."},
{"x...x.....x.....x.....x.x...x.x.....x.........x.x...x.x...x...x.."},
{"x...x.....x.xxxxx.xxxxx.xxxxx.xxxxx.xxxxx.....x.xxxxx.xxxxx.xxxxx"},
{"x...x.....x.x.........x.....x.....x.x...x.....x.x...x.....x...x.."},
{"x...x.....x.x.........x.....x.....x.x...x.....x.x...x.....x...x.."},
{"xxxxx.....x.xxxxx.xxxxx.....x.xxxxx.xxxxx.....x.xxxxx.xxxxx......"}};

bool in()
{
    for (int i = 0; i < 7; ++i)
        cin >> B[i];
    return (bool)cin;
}

int id(int l)
{
    for (int i = 0; i < 10; ++i)
    {
        bool b = true;
        for (int j = 0; j < 7; ++j)
            for (int k = 0; k < 5; ++k)
                if (A[j][6 * i + k] != B[j][6 * l + k])
                    b = false;
        if (b) return i;
    }
    return -1;
}

int main()
{
    while (in())
    {
        int C[2] = {}, k = 0;
        for (int i = 0; i < (B[0].size() + 1) / 6; ++i)
        {
            int l = id(i);
            if (l != -1)
                C[k] *= 10, C[k] += l;
            else
                ++k;
        }
        int m = C[0] + C[1], D[10] = {};
        for (int i = 9; m; --i)
            D[i] = m % 10, m /= 10;
        for (int i = 0; i < 7; ++i)
        {
            int j = 0; while (!D[j]) ++j;
            for (; j < 10; ++j)
            {
                for (int k = 0; k < 5; ++k)
                    cout << A[i][6 * D[j] + k];
                if (j != 9) cout << '.';
            }
            cout << '\n';
        }
    }
}
