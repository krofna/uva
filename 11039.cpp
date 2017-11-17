#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int p, n, A[500000];
    cin >> p;
    while (p--)
    {
        cin >> n;
        for (int i = 0; i < n; ++i)
            cin >> A[i];
        sort(A, A + n, [](int a, int b){return abs(a)>abs(b);});
        n = distance(A, unique(A, A + n, [](int a, int b)
        {
            return (abs(a) == abs(b)) || (a < 0 == b < 0);
        }));
        cout << n << '\n';
    }
}
