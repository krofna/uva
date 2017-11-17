#include <iostream>
using namespace std;

int main()
{
    int t, u = 1;
    cin >> t;
    while (t--)
    {
        int n, m = 0, in;
        cin >> n;
        while (n--)
        {
            cin >> in;
            m = max(m, in);
        }
        cout << "Case " << u++ << ": " << m << '\n';
    }
}
