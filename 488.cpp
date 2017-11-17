#include <iostream>
using namespace std;

void print(int i)
{
    for (int j = 0; j < i; ++j)
        cout << i;
    cout << '\n';            
}

int main()
{
    ios_base::sync_with_stdio(false);
    int t, a, f;
    cin >> t;
    while (t--)
    {
        cin >> a >> f;
        for (int n = 0; n < f; ++n)
        {
            for (int i = 1; i < a; ++i)
                print(i);
            for (int i = a; i > 0; --i)
                print(i);
            if (t || n != f - 1) cout << '\n';
        }
    }
}
