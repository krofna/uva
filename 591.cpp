#include <iostream>
using namespace std;

int main()
{
    int k = 1, n, H[50];
    while (cin >> n, n)
    {
        int num = 0, mean = 0;
        for (int i = 0; i < n; ++i)
        {
            cin >> H[i];
            mean += H[i];
        }
        mean /= n;
        for (int i = 0; i < n; ++i)
            num += abs(mean - H[i]);

        cout << "Set #" << k++ << '\n';
        cout << "The minimum number of moves is " << num / 2 << ".\n\n";
    }
}
