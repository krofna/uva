#include <iostream>
using namespace std;

bool in(string& s)
{
    getline(cin, s);
    if (!cin || s.empty())
        return false;
    
    string z;
    while (getline(cin, z), !z.empty()) s += "!" + z;
    return true;
}

int main()
{
    string s;
    bool f = false;
    while (in(s))
    {
        if (f) cout << '\n';
        f = true;
        int k = 0;
        string o;
        for (char c : s)
        {
            if (isdigit(c)) k += c - '0';
            else if (c == '!') o += '\n';
            else if (c == 'b') o += string(k, ' '), k = 0;
            else o += string(k, c), k = 0;
        }
        cout << o << '\n';
    }
}
