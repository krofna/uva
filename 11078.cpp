#include <iostream>
using namespace std;

int main()
{
    int t, n, A[100000];
    cin >> t;
    while (t--)
    {
        cin >> n;
        for (int i = 0; i < n; ++i)
            cin >> A[i];
        int cm = A[0], d = -300000;
        for (int i = 1; i < n; ++i)
            d = max(d, cm - A[i]), cm = max(cm, A[i]);
        cout << d << '\n';
    }
}
