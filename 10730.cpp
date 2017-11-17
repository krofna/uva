#include <iostream>
using namespace std;

int main()
{
    string s;
    while (cin >> s, s != "0")
    {
        s.pop_back();
        int n = stoi(s), A[10000];
        for (int i = 0; i < n; ++i)
            cin >> A[i];

        bool a = false;
        for (int i = 0; i < n - 2; ++i)
            for (int j = i + 1; j < n - 1; ++j)
                for (int k = j + 1; k < n; ++k)
                    if ((a = (A[i] - A[j] == A[j] - A[k])))
                        goto brk;
    brk:
        cout << (a ? "no" : "yes") << '\n';
    }
}
