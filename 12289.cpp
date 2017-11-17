#include <iostream>
#include <string>
using namespace std;

const string S[] = { "one", "two" };

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string in;
        cin >> in;
        if (in.size() == 3)
        {
            for (int i = 0; i < 2; ++i)
            {
                int m = 0;
                for (int j = 0; j < 3; ++j)
                    if (in[j] == S[i][j])
                        ++m;
                
                if (m >= 2)
                    cout << i + 1 << '\n';
            }
        }
        else
            cout << 3 << '\n';
    }
}
