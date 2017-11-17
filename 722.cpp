#include <iostream>
using namespace std;

string G[100];
int t, r, c, n;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

int flood(int r, int c)
{
    if (!(r >= 0 && c >= 0 && r < n && c < G[0].size() && G[r][c] == '0'))
        return 0;

    G[r][c] = '1';
    int sum = 1;
    for (int k = 0; k < 4; ++k)
        sum += flood(r + dy[k], c + dx[k]);
    return sum;
}

int main()
{
    ios::sync_with_stdio(false);
    cin >> t;
    while (t--)
    {       
        cin >> r >> c;
        cin.ignore();
        n = 0;
        while (getline(cin, G[n]), !G[n].empty()) n++;
        cout << flood(r - 1, c - 1) << '\n';
        if (t) cout << '\n';
    }
}
