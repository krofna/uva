#include <iostream>
#include <sstream>
#include <queue>
#include <tuple>
using namespace std;

string G[99], s;
int t, n, rr, cc, x, y;

const int dx[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
const int dy[] = { 1, 0, -1, 1, -1, 1, 0, -1 };

int flood()
{
    bool B[99][99] = {};
    queue<pair<int, int> > Q;
    Q.emplace(rr, cc);
    int cnt = 0;
    B[rr][cc] = true;
    while (!Q.empty())
    {
        tie(x, y) = Q.front();
        Q.pop();
        for (int k = 0; k < 8; ++k)
        {
            int xx = x + dx[k];
            int yy = y + dy[k];
            if (xx >= 0 && xx < n && yy >= 0 &&
                y < G[0].size() && !B[xx][yy] && G[xx][yy] == 'W')
            {
                B[xx][yy] = true;
                Q.emplace(xx, yy);
            }
        }
        ++cnt;
    }
    return cnt;
}

int main()
{
    cin >> t;
    cin.ignore(2);
    while (t--)
    {        
        n = 0;
        while (getline(cin, s), isalpha(s[0]))
            G[n++] = s;

        do
        {
            istringstream iss(s);
            iss >> rr >> cc;
            --rr; --cc;
            cout << flood() << '\n';
        }
        while (getline(cin, s), !s.empty());
        if (t) cout << '\n';
    }
}
