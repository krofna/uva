#include <iostream>
using namespace std;

int main()
{
    int a, b, c, d;
    while (cin >> a >> b >> c >> d, a || b || c || d)
        cout << 1080 + 9 * ((40 - b + a) % 40 + 40 - (40 - c + b) % 40 + (40 - d + c) % 40) << '\n';
}

