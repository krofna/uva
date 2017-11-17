#include <iostream>
using namespace std;

int main()
{
    int Q, s, x;
    cin >> Q;
    for (int t = 1; t <= Q; ++t)
    {
        cin >> s;
        int sum = 0, mx = 0, a = 0, b = 0, c = 0;
        for (int i = 0; i < s - 1; ++i)
        {
            cin >> x;
            sum += x;
            if (sum > mx || (sum == mx && i + 1 - c > b - a))
            {
                a = c;
                b = i + 1;
                mx = sum;
            }
            if (sum < 0) sum = 0, c = i + 1;
        }
        if (a == b)
            cout << "Route " << t << " has no nice parts\n";
        else
            cout << "The nicest part of route " << t << " is between stops " << a + 1 << " and " << b + 1 << '\n';
    }
}
