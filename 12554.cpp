#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    string A[100], B[4] = { "Happy", "birthday", "to", "you" };
    for (int i = 0; i < n; ++i)
        cin >> A[i];
    
    int rep = 1 + (n - 1) / 16;
    for (int i = 0; i < rep * 16; ++i)
        cout << A[i % n] << ": " << ((i % 16 != 11) ? B[i % 4] : "Rujia") << '\n';
}
