#include <iostream>
#include <iomanip>
#include <algorithm>
#include <numeric>
using namespace std;

int main()
{
    int t, n;
    cin >> t;
    while (t--)
    {
        cin >> n;
        int A[1000];
        for (int i = 0; i < n; ++i)
            cin >> A[i];
        int sum = accumulate(A, A + n, 0);
        int ctr = count_if(A, A + n, [&](int k){return k * n > sum;});
        cout << fixed << setprecision(3) << (ctr * 100) / double(n) << "%\n";
    }
}
