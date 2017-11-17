#include <iostream>
#include <algorithm>
#include <numeric>
using namespace std;

int main()
{
    int n;
    while (cin >> n, n)
    {
        cin.ignore();
        int mi = 25, A[13];
        for (int i = 0; i < n; ++i)
        {
            string s;
            getline(cin, s);
            mi = min(mi, A[i] = count(s.begin(), s.end(), ' '));
        }
        cout << accumulate(A, A + n, 0) - n * mi << '\n';
    }
}
