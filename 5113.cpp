#include <iostream>
using namespace std;

int main()
{
    int t, n, a, d;
    cin >> t;
    while (t--)
    {
        cin >> n >> a >> d;
        cout << n * a - d * n + d * n * (n + 1) / 2 << '\n';
    }
}
