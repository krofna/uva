#include <iostream>
using namespace std;

int main()
{
    int t, l, w, h;
    while (cin >> t, t)
    {
        int mh = 0, ml, mw;
        for (int i = 0; i < t; ++i)
        {
            cin >> l >> w >> h;
            if (h > mh || (h == mh && l * w * h > ml * mw * mh))
            {
                ml = l;
                mw = w;
                mh = h;
            }
        }
        cout << ml * mw * mh << '\n';
    }
}
