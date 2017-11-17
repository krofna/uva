#include <iostream>
#include <iterator>
using namespace std;

int main()
{
    string s;
    while (cin >> s)
    {
        copy(s.rbegin(), s.rend(), ostream_iterator<char>(cout));
        cout << (char)cin.peek();
    }
}
