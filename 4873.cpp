#include <iostream>
using namespace std;

int main()
{
    int t, n;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> n >> s;
        cout << n;
        int k = ((s[0] == 'H') << 2) | ((s[1] == 'H') << 1), A[8] = {};
        for (int i = 2; i < s.size(); ++i)
        {
            k |= (s[i] == 'H');
            A[k & 7]++;
            k <<= 1;
        }
        for (int i = 0; i < 8; ++i)
            cout << " " << A[i];
        cout << '\n';
    }
}
