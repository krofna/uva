#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int N;
    while (cin >> N, N)
    {
        bool f = true;
        string A = "0123456798";
        do
        {
            string aa = A.substr(0, 5);
            string bb = A.substr(5, 5);
            int a = stoi(aa);
            int b = stoi(bb);
            if (a % b == 0 && a / b == N)
                cout << aa << " / " << bb << " = " << N << '\n', f = false;
        } while (next_permutation(A.begin(), A.end()));
        if (f) cout << "There are no solutions for " << N << ".\n";
        cout << '\n';
    }
}
