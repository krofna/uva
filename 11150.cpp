#include <iostream>
using namespace std;

int main()
{
    int n;
    while (cin >> n)
    {
        int sum = 0, p = 0;
        while (n)
        {
            sum += n;
            p += n % 3;
            n /= 3;
            if (p / 3) n += p / 3, p %= 3;
        }
        cout << (p == 2 ? sum + 1 : sum) << '\n';
    }
}
