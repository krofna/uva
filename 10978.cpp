#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    while (cin >> n, n)
    {
        vector<string> A(n);
        int k = 0;
        for (int i = 0; i < n; ++i)
        {
            string a, b;
            cin >> a >> b;
            for (int j = 0; j < b.size(); ++j)
            {
                while (!A[k].empty()) ++k, k %= n;
                ++k, k %= n;
            }
            if (k == 0) k = n;
            A[--k] = a;
        }
        for (int i = 0; i < A.size(); ++i)
        {
            if (i) cout << ' ';
            cout << A[i];
        }
        cout << '\n';
    }
}
