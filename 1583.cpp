#include <iostream>
using namespace std;

int main()
{
    int t, n;
    cin >> t;
    while (t--)
    {
        cin >> n;
        int gen = 0;
        for (int i = n - 9 * 5; i < n; ++i)
        {
            int k = i, m = i;
            while (k)
            {
                m += k % 10;
                k /= 10;
            }
            if (m == n)
            {
                gen = i;
                break;
            }
        }
        cout << gen << '\n';
    }
}
