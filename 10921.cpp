#include <iostream>
using namespace std;

const char* A[]
{
    "ABC", "DEF", "GHI", "JKL", "MNO", "PQRS", "TUV", "WXYZ"
};

int main()
{
    string ln;
    while (cin >> ln)
    {
        for (int i = 0; i < ln.size(); ++i)
            for (int j = 0; j < sizeof(A) / sizeof(const char*); ++j)
                for (int k = 0; A[j][k]; ++k)
                    if (ln[i] == A[j][k])
                        ln[i] = '0' + j + 2;
    
        cout << ln << '\n';
    }
}
