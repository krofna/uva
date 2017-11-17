// TODO: vidi krofnino: ima formulu
#include <iostream>
using namespace std;

int main()
{
    int n, k;
    while (cin >> n >> k)
    {
        int cig = n, opu = 0, sum = 0;
        while (cig)
        {
            opu += cig;
            sum += cig;
            cig = opu / k;
            opu %= k;
        }
        cout << sum << '\n';
    }
}
