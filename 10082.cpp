#include <iostream>
using namespace std;

const string A[] =
{
    "`1234567890-=",
    "QWERTYUIOP[]\\",
    "ASDFGHJKL;'",
    "ZXCVBNM,./",
    "  "
};

int main()
{
    int k;
    string s;
    while (getline(cin, s))
    {
        for (int i = 0; i < s.size(); ++i)
            for (int j = 0; j < sizeof(A) / sizeof(string); ++j)
                if ((k = A[j].find(s[i], 1)) != string::npos)
                    cout << A[j][k - 1];
        cout << '\n';
    }
}
