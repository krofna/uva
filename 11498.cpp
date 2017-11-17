#include <iostream>
#include <string>
using namespace std;

const string A[2][2]
{
    { "NO", "NE" },
    { "SO", "SE" }
};

int main()
{
    int k;
    while (cin >> k, k)
    {
        int n, m;
        cin >> n >> m;
        while (k--)
        {
            int x, y;
            cin >> x >> y;
            if (x == n || y == m) cout << "divisa\n";
            else cout << A[y < m][x > n] << '\n';
        }
    }
}
