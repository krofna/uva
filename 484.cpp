#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main()
{
    int x;
    map<int, int> M;
    vector<int> V;
    while (cin >> x)
        if (!M[x]++)
            V.push_back(x);

    for (int x : V)
        cout << x << " " << M[x] << '\n';
}
