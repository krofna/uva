#include <iostream>
#include <vector>
using namespace std;

typedef vector<string> vs;

vs rot(const vs& A)
{
    vs B(A.size(), string(A.size(), 0));
    for (int i = 0; i < A.size(); ++i)
        for (int j = A.size() - 1; j >= 0; --j)
            B[i][A.size() - j - 1] = A[j][i];
    return B;
}

vs ref(const vs& A)
{
    vs B = A;
    for (int i = 0; i < A.size() / 2; ++i)
        for (int j = 0; j < A.size(); ++j)
            swap(B[i][j], B[A.size() - i - 1][j]);
    return B;
}

const string O[] =
{
    "preserved",
    "rotated 90 degrees",
    "rotated 180 degrees",
    "rotated 270 degrees",
    "reflected vertically",
    "reflected vertically and rotated 90 degrees",
    "reflected vertically and rotated 180 degrees",
    "reflected vertically and rotated 270 degrees",
};

int main()
{
    int n, t = 1;
    while (cin >> n)
    {
        vs A[8], B;
        for (int i = 0; i < n; ++i)
        {
            string a, b;
            cin >> a >> b;
            A[0].push_back(a);
            B.push_back(b);
        }
        for (int i = 0; i < 3; ++i)
            A[i + 1] = rot(A[i]);
        A[4] = ref(A[0]);
        for (int i = 4; i < 7; ++i)
            A[i + 1] = rot(A[i]);
        cout << "Pattern " << t++ << " was ";
        bool f = true;
        for (int i = 0; i < 8 && f; ++i)
            if (B == A[i])
                cout << O[i] << ".\n", f = false;
        if (f)
            cout << "improperly transformed.\n";
    }
}
