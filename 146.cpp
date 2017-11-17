#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    string s;
    while (getline(cin, s) && s != "#")
    {
        if (next_permutation(s.begin(), s.end()))
            cout << s << '\n';
        else
            cout << "No Successor" << '\n';
    }
}
