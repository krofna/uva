#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    int w, h, n, A[500][500];
    while (cin >> w >> h >> n, w || h || n)
    {
        memset(A, 0, sizeof(A));
        for (int i = 0; i < n; ++i)
        {
            int x1, y1, x2, y2;
            cin >> x1 >> y1 >> x2 >> y2;
            --x1; --y1; --x2; --y2;
            if (x1 > x2) swap(x1, x2);
            if (y1 > y2) swap(y1, y2);
            for (int y = y1; y <= y2; ++y)
                for (int x = x1; x <= x2; ++x)
                    A[y][x] = 1;
        }
        int sum = w * h;
        for (int y = 0; y < h; ++y)
            for (int x = 0; x < w; ++x)
                sum -= A[y][x];
        if (sum == 0)
            cout << "There is no empty spots.\n";
        else if (sum == 1)
            cout << "There is one empty spot.\n";
        else
            cout << "There are " << sum << " empty spots.\n";
    }
}
