#include <iostream>
using namespace std;

const string S = "WNESWN";
const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};

int main()
{
    int w, h, x, y;
    char o;
    bool SC[52][52] = {};
    string s;
    cin >> w >> h;
    while (cin >> x >> y >> o >> s)
    {
        bool l = false;
        for (int i = 0; i < s.size() && !l; ++i)
        {
            int xx = x, yy = y;
            if (s[i] == 'F')
            {
                xx += dx[S.find(o, 1) - 1];
                yy += dy[S.find(o, 1) - 1];
            }
            else
                o = S[S.find(o, 1) + (s[i] == 'R' ? 1 : -1)];

            if (xx > w || yy > h || xx < 0 || yy < 0)
            {
                if (!SC[y][x])
                    l = true;
                SC[y][x] = true;                    
            }
            else
            {
                x = xx;
                y = yy;
            }
        }
        cout << x << ' ' << y << ' ' << o;
        if (l)
            cout << " LOST";
        cout << '\n';
    }
}
