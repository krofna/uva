#include <iostream>
#include <vector>
using namespace std;

#ifdef PRECOMPUTE
#include <iomanip>

vector<int> A[4];
const int ipow[4] = { 10, 100, 1000, 10000 };

int main()
{
    for (int i = 0; i < 4; ++i)
    {
        for (int j = 0; j < ipow[i] * ipow[i]; ++j)
        {
            int a = j / ipow[i], b = j % ipow[i];
            int lhs = (a + b) * (a + b), rhs = ipow[i] * a + b;
            if (lhs == rhs)
                A[i].push_back(rhs);
        }
    }
    int n;
    while (cin >> n)
        for (int i : A[n / 2 - 1])           
            cout << setfill('0') << setw(n) << i << '\n';
}

#else

const vector<string> A[4] =
{
    { "00",
      "01",
      "81" },
    { "0000",
      "0001",
      "2025",
      "3025",
      "9801" },
    { "000000",
      "000001",
      "088209",
      "494209",
      "998001" },
    { "00000000",
      "00000001",
      "04941729",
      "07441984",
      "24502500",
      "25502500",
      "52881984",
      "60481729",
      "99980001" }
};

int main()
{
    int n;
    while (cin >> n)
        for (string s : A[n / 2 - 1])           
            cout << s << '\n';
}

#endif
