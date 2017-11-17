#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    int n, k;
    while (cin >> n, n)
    {
        vector<int> A;
        for (int i = 0; i < n; ++i)
        {
            cin >> k;
            A.push_back(k);
        }
        sort(A.begin(), A.end());
        A.push_back(A.back() + (1422 - A.back()) * 2);

        bool possible = true;
        for (int i = 1; i < A.size() && possible; ++i)
            if (A[i] - A[i - 1] > 200)
                possible = false;

        cout << (possible ? "POSSIBLE\n" : "IMPOSSIBLE\n");
    }
}
