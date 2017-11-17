#include <iostream>
using namespace std;

int main()
{
    int n;
    while (cin >> n, n)
    {
        int sum = 0, ans = 0, x;
        for (int i = 0; i < n; ++i)
        {
            cin >> x;
            sum += x;
            ans = max(ans, sum);
            sum = max(sum, 0);
        }
        if (ans <= 0)
            cout << "Losing streak.\n";
        else
            cout << "The maximum winning streak is " << ans << ".\n";
    }
}
