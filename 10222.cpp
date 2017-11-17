#include <iostream>
using namespace std;

const string A[] =
{
    "`1234567890-=",
    "qwertyuiop[]\\",
    "asdfghjkl;'",
    "<zxcvbnm,./"
};

int main()
{
    string s;
    while (getline(cin, s), cin)
    {
        for (int i = 0; i < s.size(); ++i)
        {
            if (s[i] != ' ')
            {
                for (int j = 0; j < sizeof(A) / sizeof(string); ++j)
                    for (int k = 1; k < A[j].size(); ++k)
                        if (s[i] == A[j][k])
                            cout << A[j][k - 2];
            }
            else
                cout << ' ';
        }
        cout << '\n';
    }
}
