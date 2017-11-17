#include <iostream>
using namespace std;

int main()
{
    int t, n, m;
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        if (n < m)
            cout << "NO BRAINS\n";
        else
            cout << "MMM BRAINS\n";
    }
}
