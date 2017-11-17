#include <iostream>
#include <map>
using namespace std;

int main()
{
    int n;
    cin >> n;
    map<string, int> M;
    for (int i = 0; i < n; ++i)
    {
        string s, z;
        cin >> s;
        getline(cin, z);
        M[s]++;
    }
    for (auto& si : M)
        cout << si.first << " " << si.second << '\n';
}
