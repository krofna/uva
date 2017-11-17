#include <iostream>
#include <algorithm>
#include <cstring>
#include <climits>
using namespace std;

int A[9];

bool input()
{
    for (int i = 0; i < 9; ++i)
        cin >> A[i];
    return static_cast<bool>(cin);
}

string gen(int* q)
{
    string S = "BGC", s;
    for (int i = 0; i < 3; ++i)
        s += S[q[i]];
    return s;
}

int main()
{
    while (input())
    {
        int p[3] = {0, 1, 2}, q[3] = { 2, 2, 2 }, min = INT_MAX;
        do
        {
            int sum = 0;
            for (int i = 0; i < 3; ++i)
                for (int j = 0; j < 3; ++j)
                    if (j != p[i])
                        sum += A[i * 3 + j];

            if (sum < min || (sum == min && gen(p) < gen(q)))
            {
                min = sum;
                memcpy(q, p, sizeof(p));
            }
        } while (next_permutation(p, p + 3));
        cout << gen(q) << ' ' << min << '\n';
    }
}
