#include <iostream>
using namespace std;

int main()
{
    int t, max;
    int R[10];
    string W[10];
    cin >> t;
    for (int i = 0; i < t; ++i)
    {
        max = 0;
        for (int j = 0; j < 10; ++j)
        {
            cin >> W[j] >> R[j];
            if (R[j] > max)
                max = R[j];
        }
        cout << "Case #" << i + 1 << ":\n";
        for (int j = 0; j < 10; ++j)
            if (R[j] == max)
                cout << W[j] << '\n';
    }
}
