#include <iostream>
#include <iomanip>
using namespace std;

double f(int i)
{
    return i == 0 ? 1 : i * f(i - 1);
}

int main()
{
    cout << "n e\n";
    cout << "- -----------\n";
    cout << setprecision(10);
    for (int n = 0; n <= 9; ++n)
    {
        double e = 0;
        for (int i = 0; i <= n; ++i)
            e += 1. / f(i);
        cout << n << " " << e << '\n';
    }
}
