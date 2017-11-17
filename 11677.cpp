#include <iostream>
using namespace std;

int main()
{
    int h1, m1, h2, m2;
    while (cin >> h1 >> m1 >> h2 >> m2, h1 || h2 || m1 || m2)
    {
        m1 += h1 * 60;
        m2 += h2 * 60;
        if (m1 > m2)
            cout << 24 * 60 - m1 + m2 << '\n';
        else
            cout << m2 - m1 << '\n';
    }
}
