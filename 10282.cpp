#include <iostream>
#include <sstream>
#include <map>
using namespace std;

int main()
{
    map<string, string> M;
    string s, a, b;
    while (getline(cin, s), !s.empty())
    {
        istringstream iss(s);
        iss >> a >> b;
        M[b] = a;
    }
    while (cin >> s)
    {
        auto i = M.find(s);
        cout << (i != M.end() ? i->second : "eh") << '\n';
    }
}
