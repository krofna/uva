#include <iostream>
using namespace std;

int main()
{
    unsigned a, b;
    while (cin >> a >> b, a || b)
    {
        unsigned num = 0, carry = 0;
        while (a || b)
        {
            int sum = a % 10 + b % 10 + carry;
            a /= 10;
            b /= 10;
            if (sum >= 10)
            {
                num += 1;
                carry = 1;
            }
            else
                carry = 0;
        }
        if (num)
            cout << num;
        else
            cout << "No";
        cout << " carry operation";
        if (num > 1)
            cout << 's';
        cout << ".\n";
    }
}
