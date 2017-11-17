#include <iostream>
using namespace std;

int main()
{
    int t, n, x, A[100];
    string s;
    cin >> t;
    while (t--)
    {
        cin >> n;
        int pos = 0;
        for (int i = 0; i < n; ++i)
        {
            cin >> s;
            switch (s[0])
            {
                case 'L': A[i] = -1; break;
                case 'R': A[i] = 1; break;
                default: cin >> s >> x; A[i] = A[x - 1]; break;
            }
            pos += A[i];
        }
        cout << pos << '\n';
    }
}
