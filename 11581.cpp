#include <iostream>
#include <array>
using namespace std;

typedef array<string, 3> as;
int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};

as f(as& a)
{
    as b; b.fill(string(3, 0));
    for (int y = 0; y < 3; ++y)
    {
        for (int x = 0; x < 3; ++x)
        {
            int sum = 0;
            for (int k = 0; k < 4; ++k)
            {
                int yy = y + dy[k], xx = x + dx[k];
                if (yy >= 0 && xx >= 0 && yy < 3 && xx < 3)
                    sum += a[yy][xx] - '0';
            }
            b[y][x] = '0' + (sum % 2);
        }
    }
    return b;
}

int kg(as& s)
{
    as b = f(s), z; z.fill(string(3, '0'));
    int i;
    for (i = 0; b != z && b != s; ++i)
        b = f(b);
    return b == s ? -1 : i;
}

int main()
{
    int t;
    cin >> t;
    as s;    
    while (t--)
    {
        for (int i = 0; i < 3; ++i)
            cin >> s[i];
        cout << kg(s) << '\n';
    }
}
