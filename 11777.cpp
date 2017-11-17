#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int t;
    cin >> t;
    for (int q = 1; q <= t; ++q)
    {
        int sum = 0, k, A[3];
        for (int i = 0; i < 4; ++i)
            cin >> k, sum += k;
        for (int i = 0; i < 3; ++i)
            cin >> A[i];
        sort(A, A + 3);
        sum += (A[1] + A[2]) / 2;
        char g = 'F';
        if (sum >= 90)
            g = 'A';
        else if (sum >= 80)
            g = 'B';
        else if (sum >= 70)
            g = 'C';
        else if (sum >= 60)
            g = 'D';
        cout << "Case " << q << ": " << g << '\n';
    }
}
