#include <iostream>
#include <algorithm>
using namespace std;

const size_t SZ = 'Z' - 'A' + 1;

int main()
{
    string s;
    while (getline(cin, s))
    {
        int A[SZ] = {0};
        int B[SZ] = {0};
        for (char c : s)
        {
            if (isupper(c))
                A[c - 'A']++;
            else if (islower(c))
                B[c - 'a']++;
        }
        int ma = *max_element(A, A + SZ);
        int mb = *max_element(B, B + SZ);
        int mm = max(ma, mb);
        for (int i = 0; i < SZ; ++i)
            if (A[i] == mm)
                cout << char('A' + i);
        for (int i = 0; i < SZ; ++i)
            if (B[i] == mm)
                cout << char('a' + i);
        cout << ' ' << mm << '\n';
    }
}
