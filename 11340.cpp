#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    int n, k, m, v;
    unsigned char c;
    cin >> n;
    while (n--)
    {
        cin >> k;
        int C[256] = {};
        while (k--)
        {
            cin >> c >> v;
            C[c] = v;
        }
        cin >> m;
        cin.ignore();
        int cost = 0;
        while (m--)
        {
            string s;
            getline(cin, s);
            for (unsigned char p : s)
                cost += C[p];
        }
        cout << cost / 100 << '.';
        if (cost % 100 < 10)
            cout << '0';
        cout << cost % 100 << "$\n";
    }
}
