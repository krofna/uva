#include <iostream>
using namespace std;

int main()
{
    string in;
    int t = 1;
    while (cin >> in, in != "*")
    {
        cout << "Case " << t++ << ": ";
        if (in == "Hajj")
            cout << "Hajj-e-Akbar\n";
        else
            cout << "Hajj-e-Asghar\n";
    }
}
