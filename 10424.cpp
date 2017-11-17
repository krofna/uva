#include <iomanip>
#include <iostream>
using namespace std;

int f(int n)
{
    int m = 0;
    while (n)
    {
        m += n % 10;
        n /= 10;
    }
    return m;
}

int main()
{
    string in[2];
    while (getline(cin, in[0]) && getline(cin, in[1]))
    {
        int sum[2] = {0};
        for (int i = 0; i < 2; ++i)
        {
            for (char c : in[i])
                if (isalpha(c))
                    sum[i] += tolower(c) - 'a' + 1;
            
            while (sum[i] >= 10)
                sum[i] = f(sum[i]);
        }
        if (!(sum[0] == 0 && sum[1] == 0))
        {
            if (sum[0] > sum[1]) swap(sum[0], sum[1]);
            cout << fixed << setprecision(2) << 100 * (sum[0] / float(sum[1])) << " %\n";
        }
        else
            cout << '\n';
    }
}
