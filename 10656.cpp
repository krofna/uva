#include <iostream>
using namespace std;

int main()
{
    int n, in;
    bool flag;
    while (cin >> n, n)
    {
        flag = true;
        for (int i = 0; i < n; ++i)
        {
            cin >> in;
            if (in)
            {
                if (!flag)
                    cout << ' ';
                
                cout << in;
                flag = false;
            }
        }
        if (flag)
            cout << 0;
        cout << '\n';
    }
}
