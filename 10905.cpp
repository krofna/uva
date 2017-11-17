#include <iostream>
#include <algorithm>
#include <numeric>
using namespace std;

int main()
{
    int n;
    while (cin >> n, n)
    {
        string A[50];
        for (int i = 0; i < n; ++i)
            cin >> A[i];
        sort(A, A + n, [](const string& a, const string& b)
        {
            string ab = a + b, ba = b + a;
            auto ii = mismatch(ab.begin(), ab.end(), ba.begin());
            if (ii.first == ab.end()) return false;
            return *ii.first > *ii.second;
        });
        cout << accumulate(A, A + n, string()) << '\n';
    }
}
