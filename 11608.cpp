#include <iostream>
using namespace std;

int main()
{
    int s, A[12], B[12], t = 1;
    while (cin >> s, s >= 0)
    {
        cout << "Case " << t++ << ":\n";
        for (int i = 0; i < 12; ++i)
            cin >> A[i];
        for (int i = 0; i < 12; ++i)
            cin >> B[i];
        for (int i = 0; i < 12; ++i)
        {
            if (B[i] > s) cout << "No problem. :(\n";
            else cout << "No problem! :D\n", s -= B[i];
            s += A[i];
        }
    }
}
