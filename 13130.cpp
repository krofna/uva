#include <iostream>
using namespace std;

int main()
{
    int t, A[5];
    cin >> t;
    while (t--)
    {
        for (int i = 0; i < 5; ++i)
            cin >> A[i];
        bool flg = true;
        for (int i = 1; i < 5; ++i)
            flg &= A[i - 1] + 1 == A[i];
        cout << (flg ? "Y\n" : "N\n");
    }
}
