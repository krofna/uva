// TODO: pogledaj patrickovo
#include <iostream>
using namespace std;

int f(int x)
{
    int y = 0;
    while (x)
    {
        x /= 10;
        y += 1;
    }
    return y;
}

int main()
{
    string s;
    while (cin >> s && s != "END")
    {
        if (s == "1")
        {
            cout << "1\n";
            continue;
        }

        int i = 2, x = s.size();
        int y = f(x);
        while (y != x)
        {
            i += 1;
            x = y;
            y = f(x);
        }
        cout << i << '\n';
    }
}
