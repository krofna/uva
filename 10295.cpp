#include <iostream>
#include <map>
#include <sstream>
using namespace std;

int main()
{
    int m, n, d;
    string s, z;
    cin >> m >> n;
    map<string, int> M;
    for (int i = 0; i < m; ++i)
    {
        cin >> s >> d;
        M[s] = d;
    }
    cin.ignore();
    for (int i = 0; i < n; ++i)
    {
        int sum = 0;
        while (getline(cin, s), s != ".")
        {
            istringstream iss(s);
            while (iss >> z) sum += M[z];
        }
        cout << sum << '\n';
    }
}
