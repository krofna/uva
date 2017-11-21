#include <iostream>
using namespace std;

int main()
{
    int n;
    while (cin >> n, n)
    {
        int sum = 0;
        while (n / 3)
        {
            sum += n / 3;
            n = n / 3 + n % 3;
        }
        cout << (n == 2 ? sum + 1 : sum) << '\n';
    }
}
