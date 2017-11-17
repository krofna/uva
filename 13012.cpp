#include <iostream>
using namespace std;

int main()
{
    int n, x;
    while (cin >> n)
    {
        int k = 0;
        for (int i = 0; i < 5; ++i)
        {
            cin >> x;
            if (x == n)
                ++k;
        }
        cout << k << '\n';
    }
}
