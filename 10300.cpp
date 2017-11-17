#include <iostream>
using namespace std;

int main()
{
    int n, f, sz, an, pm;
    cin >> n;
    while (n--)
    {
        cin >> f;
        int sum = 0;
        while (f--)
        {
            cin >> sz >> an >> pm;
            sum += sz * pm;
        }
        cout << sum << '\n';
    }
}
