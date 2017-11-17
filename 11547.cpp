#include <iostream>
using namespace std;

int main()
{
    int t, n;
    cin >> t;
    while (cin >> n, t--)
        cout << abs(((((((n * 567) / 9 + 7492) * 235) / 47) - 498) / 10) % 10) << '\n';
}
