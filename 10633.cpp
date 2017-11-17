#include <iostream>
using namespace std;

int main()
{
    unsigned long long nm;
    while (cin >> nm, nm)
    {
        bool found = false;
        for (int i = 9; i >= 0; --i)
        {
            if (!((10 * nm - i) % 9))
            {
                if (found) cout << ' ';
                cout << (10 * nm - i) / 9;
                found = true;
            }
        }
                
        cout << '\n';
    }
}
