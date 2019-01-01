#include <iostream>
#include <vector>
#include <utility>
#include <tuple>
using namespace std;

vector<vector<int> > A;
vector<pair<int, int> > B;

void bl(int k, int x)
{
    B[k] = make_pair(x, A[x].size());
    A[x].push_back(k);
}

void ret(int v)
{
    int x, y;
    tie(x, y) = B[v];
    for (int j = y + 1; j < A[x].size(); ++j)
        bl(A[x][j], A[x][j]);
    A[x].resize(y + 1);
}

void mv(int a, int b)
{
    int xa, ya, xb, yb;
    tie(xa, ya) = B[a];
    tie(xb, yb) = B[b];
    for (int j = ya; j < A[xa].size(); ++j)
        bl(A[xa][j], xb);
    A[xa].resize(ya);
}

int main()
{
    int n, a, b;
    cin >> n;
    A.resize(n);
    for (int i = 0; i < n; ++i)
        A[i].push_back(i), B.emplace_back(i, 0);

    string sa, sb;
    while (cin >> sa, sa != "quit")
    {
        cin >> a >> sb >> b;
        if (a == b || B[a].first == B[b].first)
            continue;
        if (sa == "move")
            ret(a);
        if (sb == "onto")
            ret(b);
        mv(a, b);
    }
    for (int i = 0; i < A.size(); ++i)
    {
        cout << i << ":";
        for (int j = 0; j < A[i].size(); ++j)
            cout << " " << A[i][j];
        cout << '\n';
    }
}
