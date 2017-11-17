// TODO: vidi krofnino
#include <iostream>
using namespace std;

int main()
{
    int t, a, b;
    cin >> t;
    for (int k = 1; k <= t; ++k)
    {
        cin >> a >> b;
        int sum = 0;
        for (int i = a; i <= b; ++i)
            if (i % 2)
                sum += i;
        cout << "Case " << k << ": " << sum << '\n';
    }
}
