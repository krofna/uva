#include <iostream>
using namespace std;

int main()
{
    int t, i = 1;
    cin >> t;
    while (t--)
    {
        int l, w, h;
        cin >> l >> w >> h;
        cout << "Case " << i++ << ": ";
        if (l <= 20 && w <= 20 && h <= 20)
            cout << "good\n";
        else
            cout << "bad\n";
    }
}
