#include <iostream>
#include <set>
#include <iterator>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    set<string> S;
    string s, t;
    while (cin)
    {
        s.clear();
        while (cin && !isalpha(cin.peek()))
            cin.ignore();
        while (cin && isalpha(cin.peek()))
            s += tolower(cin.get());
        if (!s.empty())
            S.insert(s);
    }
    copy(S.begin(), S.end(), ostream_iterator<string>(cout, "\n"));
}
