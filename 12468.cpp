// TODO: vidi krofnino
#include <iostream>
using namespace std;

int main()
{
    int a, b;
    while (cin >> a >> b, a >= 0)
    {
        int dd = abs(max(a, b) - 100 - min(a, b));
        cout << min(abs(b - a), dd) << '\n';
    }
}
