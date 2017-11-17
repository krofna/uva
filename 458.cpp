#include <iostream>
using namespace std;

int main()
{
    string in;
    while (cin >> in)
    {
        for (char c : in)
            cout << char(c - 7);
        cout << '\n';
    }
}
