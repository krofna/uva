#include <iostream>
#include <sstream>
#include <cstring>
using namespace std;

string line, name;
char cmd, A[251][251], c;
int m, n, x1, x2, y1, y2, x, y;

void Fill(int x, int y, const char c, const char oc)
{
    static const int dx[] = { 1, -1, 0, 0 };
    static const int dy[] = { 0, 0, 1, -1 };
    A[y][x] = c;
    for (int k = 0; k < 4; ++k)
    {
        int xx = x + dx[k], yy = y + dy[k];
        if (xx <= m && xx > 0 && yy <= n && yy > 0 && A[yy][xx] == oc)
            Fill(xx, yy, c, oc);
    }
}

int main()
{
    while (getline(cin, line), cin)
    {
        istringstream ss(line);
        ss >> cmd;
        switch (cmd)
        {
            case 'I':
                ss >> m >> n;
            case 'C':
                memset(A, 'O', sizeof(A));
                break;
            case 'L':
                ss >> x >> y >> c;
                A[y][x] = c;
                break;
            case 'V':
                ss >> x >> y1 >> y2 >> c;
                for (int i = min(y1, y2); i <= max(y1, y2); ++i)
                    A[i][x] = c;
                break;
            case 'H':
                ss >> x1 >> x2 >> y >> c;
                for (int i = min(x1, x2); i <= max(x1, x2); ++i)
                    A[y][i] = c;
                break;
            case 'K':
                ss >> x1 >> y1 >> x2 >> y2 >> c;
                for (int i = min(y1, y2); i <= max(y1, y2); ++i)
                    for (int j = min(x1, x2); j <= max(x1, x2); ++j)
                        A[i][j] = c;
                break;
            case 'F':
                ss >> x >> y >> c;
                if (c != A[y][x])
                    Fill(x, y, c, A[y][x]);
                break;
            case 'S':
                ss >> name;
                cout << name << '\n';
                for (int i = 1; i <= n; ++i)
                {
                    for (int j = 1; j <= m; ++j)
                        cout << A[i][j];
                    cout << '\n';
                }
                break;
            case 'X':
                return 0;
        }
    }
}
