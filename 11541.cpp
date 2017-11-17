#include <iostream>
#include <iterator>
using namespace std;

int main()
{
    string s;
    int n;
    cin >> n;
    for (int u = 1; u <= n; ++u)
    {
        cout << "Case " << u << ": ";
        cin >> s;
        for (int i = 0; i < s.size(); ++i)
        {
            int rep = 0;
            char c = s[i];
            while (isdigit(s[i + 1]))
                rep *= 10, rep += (s[i + 1] - '0'), ++i;
            fill_n(ostream_iterator<char>(cout), rep, c);
        }
        cout << '\n';
    }
}
