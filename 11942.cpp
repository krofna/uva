#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n, A[10];
    cin >> n;
    cout << "Lumberjacks:\n";
    while (n--)
    {
        for (int i = 0; i < 10; ++i)
            cin >> A[i];
        
        if (is_sorted(A, A + 10) || is_sorted(A, A + 10, greater<int>()))
            cout << "Ordered\n";
        else
            cout << "Unordered\n";
    }
}
