#include <iostream>
#include <cmath>
using namespace std;

void f(string& s, size_t i, int& x, int& c)
{
    do
    {
        size_t d = s.find_first_of("+-", i + 1);
        if (d == s.npos) d = s.size();
        string z = s.substr(i, d - i);
        if (z.back() == 'x')
        {
            string w = z.substr(0, z.size() - 1);
            if (w.empty() || w == "+") x += 1;
            else if (w == "-") x -= 1;
            else x += stoi(w);
        }
        else
            c += stoi(z);
        i = d;
    } while (i < s.size());
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        size_t e = s.find('=');
        string a = s.substr(0, e), b = s.substr(e + 1);
        int x = 0, y = 0, c = 0, d = 0;
        f(a, 0, x, c);
        f(b, 0, y, d);
        int rx = x - y, rc = d - c;
        if (rx == 0)
            cout << (rc == 0 ? "IDENTITY\n" : "IMPOSSIBLE\n");
        else
            cout << (int)floor(float(rc) / rx) << '\n';
    }
}
