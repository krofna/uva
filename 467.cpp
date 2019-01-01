#include <iostream>
#include <sstream>
#include <algorithm>
using namespace std;

int main()
{
    int A[20], t = 1;
    string in;
    while (getline(cin, in))
    {
        int n = 0, m = 90;
        istringstream iss(in);
        while (iss >> A[n]) ++n;
        for (int i = 0; i < n; ++i)
            iss >> A[i], m = min(m, A[i]);

        bool f = false;
        for (int i = m * 2; i <= 3600; ++i)
        {
            if (none_of(A, A + n, [&](int k)
            {
                return (i / k) % 2 || (i % k) >= k - 5;
            }))
            {
                f = true;
                cout << "Set " << t++ << " synchs again at " << i / 60
                     << " minute(s) and " << i % 60 << " second(s) after all"
                     << " turning green.\n";
                break;
            }
        }
        if (!f)
            cout << "Set " << t++ << " is unable to synch after one hour.\n";
    }
}
