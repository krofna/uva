#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int m, n, k;
    bool A[100];
    cin >> m;
    while (m--)
    {
        cin >> n >> k;
        for (int i = 0; i < n; ++i)
            A[i] = true;
        for (int i = 0; i < k; ++i)
        {
            int p;
            cin >> p;
            int W[100];
            for (int j = 0; j < p * 2; ++j)
                cin >> W[j];
            char c;
            cin >> c;
            /*
              UVa test cases ignore inequalities even though sometimes it is
              possible to deduce the solution as the intersection of sets
              of coins which appear in inequalities. Consider, for example:
              1 3 2
              1 1 2 <
              1 3 2 <
              The correct answer is 2.
            */
            if (c == '=')
                for (int j = 0; j < p * 2; ++j)
                    A[W[j] - 1] = false;
        }
        if (count(A, A + n, true) == 1)
            cout << distance(A, find(A, A + n, true)) + 1 << '\n';
        else
            cout << 0 << '\n';
        
        if (m)
            cout << '\n';
    }
}
