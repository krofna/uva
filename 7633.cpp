#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int n;
    while (cin >> n, n)
    {
        int a = round(sqrt(n));
        int b = round(cbrt(n));
        if (a * a == n && b * b * b == n)
            cout << "Special\n";
        else
            cout << "Ordinary\n";
    }
}
