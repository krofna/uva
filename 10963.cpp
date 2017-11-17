#include <iostream>
using namespace std;

int main()
{
    int t, c, y1, y2;
    cin >> t;
    while (t--)
    {
        cin >> c;
        cin >> y1 >> y2;
        int diff = abs(y1 - y2);
        bool can = true;
        while (--c)
        {
            cin >> y1 >> y2;
            if (abs(y1 - y2) != diff)
                can = false;
        }
        cout << (can ? "yes\n" : "no\n");
        if (t) cout << '\n';
    }
}
