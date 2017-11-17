// TODO: heuristika?
#include <iostream>
#include <vector>
#include <tuple>
#include <set>
#include <queue>
using namespace std;

typedef array<string, 5> as;
typedef tuple<as, int, int, int> state;

const int dx[] = { 1, 1, 2, 2, -1, -1, -2, -2 };
const int dy[] = { -2, 2, -1, 1, -2, 2, -1, 1 };

const as T =
{
    "11111",
    "01111",
    "00 11",
    "00001",
    "00000"
};

int main()
{
    int N, x, y, w;
    cin >> N;
    cin.ignore();
    while (N--)
    {
        as G;
        for (int i = 0; i < 5; ++i)
        {
            string s;
            getline(cin, s);
            G[i] = s.substr(0, 5);
        }
        
        queue<state> Q;
        for (int i = 0; i < 5; ++i)
            for (int j = 0; j < 5; ++j)
                if (G[i][j] == ' ')
                    Q.emplace(G, j, i, 0);
        
        set<state> S;
        while (!Q.empty())
        {
            tie(G, x, y, w) = Q.front();
            if (G == T)
                break;
            
            Q.pop();
            for (int i = 0; i < 8; ++i)
            {
                int xx = x + dx[i];
                int yy = y + dy[i];
                if (xx >= 0 && yy >= 0 && xx < 5 && yy < 5 && w < 10)
                {
                    as H = G;
                    swap(H[y][x], H[yy][xx]);
                    state tu = make_tuple(H, xx, yy, w + 1);
                    if (S.find(tu) == S.end())
                    {
                        Q.push(tu);
                        S.insert(tu);
                    }
                }
            }
        }

        if (!Q.empty())
            cout << "Solvable in " << w << " move(s).\n";
        else
            cout << "Unsolvable in less than 11 move(s).\n";
    }
}
