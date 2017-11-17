#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    int r, c, xs, ys, B[10][10];
    string G[10];
    while (cin >> r >> c >> xs, r && c && xs)
    {
        memset(B, 0, sizeof(B));
        xs -= 1;
        ys = 0;

        for (int y = 0; y < r; ++y)
            cin >> G[y];
        
        int i = 1, cycle = 0;
        while (ys >= 0 && xs >= 0 && ys < r && xs < c && !B[ys][xs])
        {
            B[ys][xs] = i++;
            switch (G[ys][xs])
            {
                case 'N': --ys; break;
                case 'S': ++ys; break;
                case 'E': ++xs; break;
                case 'W': --xs; break;
            }
        }

        if (ys >= 0 && xs >= 0 && ys < r && xs < c && B[ys][xs])
            cycle = i - B[ys][xs];
        
        if (cycle)
            cout << i - cycle - 1 << " step(s) before a loop of " << cycle << " step(s)\n";
        else
            cout << i - 1 << " step(s) to exit\n";
    }
}
