#include <iostream>
using namespace std;

int main()
{
    int n, l, A[50];
    cin >> n;
    while (n--)
    {
        cin >> l;
        for (int i = 0; i < l; ++i)
            cin >> A[i];
        
        int s = 0;
        for (int i = 0; i < l; ++i)
            for (int j = i + 1; j < l; ++j)
                if (A[i] > A[j])
                    s += 1;

        cout << "Optimal train swapping takes " << s << " swaps.\n";
    }
}
